//Not fast, but simple. Uses includes to check if the first sorted set includes the second one. We can re-map strings to integer ids to make it a bit //faster (second solution).

vector<int> peopleIndexes(vector<vector<string>>& favs) {
	for (auto &comps : favs)
		sort(begin(comps), end(comps));
	vector<int> res;
	for (auto i = 0; i < favs.size(); ++i) {
		bool notSubset = true;
		for (auto j = 0; j < favs.size() && notSubset; ++j) {
			if (i == j)
				continue;
			notSubset = !includes(begin(favs[j]), end(favs[j]), begin(favs[i]), end(favs[i]));
		}
		if (notSubset)
			res.push_back(i);
	}
	return res;
}
//Optimized Solution

vector<int> peopleIndexes(vector<vector<string>>& favs) {
    unordered_map<string, int> ids;
    int id = 0;
    vector<vector<int>> comps(favs.size());
    for (auto i = 0; i < favs.size(); ++i) {
        for (auto &comp : favs[i]) {
            if (!ids.count(comp)) {
                ids[comp] = id++;
            }
            comps[i].push_back(ids[comp]);
        }            
    }
    for (auto &comp: comps)
        sort(begin(comp), end(comp));
    vector<int> res;
    for (auto i = 0; i < comps.size(); ++i) {
        bool notSubset = true;            
        for (auto j = 0; j < comps.size() && notSubset; ++j) {
            if (i == j)
                continue;
            notSubset = !includes(begin(comps[j]), end(comps[j]), begin(comps[i]), end(comps[i]));
        }
        if (notSubset)
            res.push_back(i);
    }
    return res;
}