class MyCalendar {
    vector<pair<int, int>> books;
public:    
    bool book(int start, int end) {
        for (pair<int, int> p : books)
            if (max(p.first, start) < min(end, p.second)) return false;
        books.push_back({start, end});
        return true;
    }
};

class MyCalendar {
    map<int, int> books;
public:
    bool book(int s, int e) {
        auto next = books.lower_bound(s); // first element with key not go before k (i.e., either it is equivalent or goes after).
        if (next != books.end() && next->first < e) return false; // a existing book started within the new book (next)
        if (next != books.begin() && s < (--next)->second) return false; // new book started within a existing book (prev)
        books[s] = e;
        return true;
    }
};