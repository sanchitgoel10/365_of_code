vector<vector<string>> displayTable(vector<vector<string>>& orders) {
    vector<unordered_map<string, int>> tables(501);
    set<string> foods;
    for (auto &v : orders) {
        foods.insert(v[2]);
        ++tables[stoi(v[1])][v[2]];
    }
    vector<vector<string>> res;
    for (auto t = 0; t <= 500; ++t) {
        if (t > 0 && tables[t].empty())
            continue;
        res.push_back(vector<string>());
        res.back().push_back(t == 0 ? "Table" : to_string(t));
        for (auto it = begin(foods); it != end(foods); ++it) {
            res.back().push_back(t == 0 ? *it : to_string(tables[t][*it]));
        }
    }
    return res;
}