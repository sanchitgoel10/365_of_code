/*I do a BFS for each path
for example:
{hit} ->
{hit,hot} ->
{hit,hot,dot}/{hit,hot,lot} ->
["hit","hot","dot","dog"]/["hit","hot","lot","log"] ->
["hit","hot","dot","dog","cog"],
["hit","hot","lot","log","cog"]
*/

class Solution {
    public:
    /*
        The idea is to run a BFS from beginWord to endWord, while keeping track of the path.
        Once the currWord == endWord, we have found the shortest path.
        The nextLevel keeps track of all the words reachable from currLevel.
        All words in nextLevel should be erased from dict to avoid loops.( This is slight modification to the usual BFS ).
    
    */
        vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
            unordered_set< string > dict( wordList.begin(), wordList.end() );
            dict.erase( beginWord );
            queue< vector< string > > q;
            vector< vector< string > > result;
            q.push( { beginWord } );
            bool found = false;
            while( !q.empty() ) {
                int size = q.size();
                unordered_set< string > nextLevel;

                for( int i = 0 ; i < size ; ++i ) {
                    vector< string > currLevel = q.front();
                    q.pop();
                    string currWord = currLevel.back();
                    if( currWord == endWord ) {
                        found = true;
                        result.push_back( currLevel );
                    } else {
                        for( int i = 0 ; i < currWord.size() ; ++i ) {
                            char orig = currWord[ i ];
                            for( char ch = 'a' ; ch <= 'z' ; ++ch ) {
                                if( ch == orig ) continue;
                                currWord[ i ] = ch;
                                if( dict.find( currWord ) != dict.end() ) {
                                    nextLevel.insert( currWord );
                                    q.push( currLevel );             //in the current level
                                    q.back().push_back( currWord );  //add next word
                                }
                            }
                            currWord[ i ] = orig;
                        }
                    }
                }
                if( found ) break;
                for( auto n : nextLevel ) {
                    dict.erase( n );
                }
            }
            return result;
        }

};