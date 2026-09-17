class LRUCache {
public:
    unordered_map<int, pair<int, list<int> :: iterator>> rec;
    list<int>history;
    int n;
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        
        if(rec.find(key) != rec.end()){

            history.erase(rec[key].second);
            history.push_front(key);
            rec[key].second = history.begin();
        }else{

            return -1;
        }

        return rec[key].first;
    }
    
    void put(int key, int value) {
        
        if(rec.find(key) != rec.end()){

            history.erase(rec[key].second);

        }else if(history.size() >= n){
            
            int temp = history.back();
            rec.erase(temp);
            history.pop_back();
        }

        history.push_front(key);
        rec[key] = {value, history.begin()};
        
    }
};
