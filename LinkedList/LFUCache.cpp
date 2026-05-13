class LFUCache {
public:
    int cap;
    int minFreq;

    unordered_map<int, pair<int,int>> keyToValFreq; 
    // key -> {value, freq}

    unordered_map<int, list<int>> freqToKeys;
    // freq -> list of keys (LRU order)

    unordered_map<int, list<int>::iterator> keyToIter;
    // key -> iterator in freqToKeys[freq]

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (keyToValFreq.find(key) == keyToValFreq.end())
            return -1;

        int val = keyToValFreq[key].first;
        int freq = keyToValFreq[key].second;

        // Remove key from old frequency list
        freqToKeys[freq].erase(keyToIter[key]);

        // If this was the only key with minFreq, update minFreq
        if (freqToKeys[freq].empty()) {
            freqToKeys.erase(freq);
            if (minFreq == freq)
                minFreq++;
        }

        // Increase frequency
        freq++;
        keyToValFreq[key].second = freq;

        // Add key to new frequency list
        freqToKeys[freq].push_front(key);
        keyToIter[key] = freqToKeys[freq].begin();

        return val;
    }

    void put(int key, int value) {
        if (cap == 0) return;

        // If key already exists, update value & frequency
        if (keyToValFreq.find(key) != keyToValFreq.end()) {
            keyToValFreq[key].first = value;
            get(key);  // reuse get to update frequency
            return;
        }

        // If cache is full, evict LFU key
        if (keyToValFreq.size() == cap) {
            int evictKey = freqToKeys[minFreq].back(); // LRU of minFreq
            freqToKeys[minFreq].pop_back();

            if (freqToKeys[minFreq].empty())
                freqToKeys.erase(minFreq);

            keyToValFreq.erase(evictKey);
            keyToIter.erase(evictKey);
        }

        // Insert new key
        keyToValFreq[key] = {value, 1};
        freqToKeys[1].push_front(key);
        keyToIter[key] = freqToKeys[1].begin();
        minFreq = 1;
    }
};
