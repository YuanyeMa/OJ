/*
	LRU缓存机制
*/
# include <iostream>
# include <list>
# include <unordered_map>

using namespace std;

class LRUCache {
private:
	int cap;
	list<pair<int,int> > cache;
	unordered_map<int, list<pair<int,int> >::iterator > map;
public:
	LRUCache(int capacity) {
		cap = capacity;
	}
    
	int get(int key) {
    		// 在cache中查找key是否存在
		unordered_map<int, list<pair<int,int> >::iterator >::iterator it = map.find(key);
		if (it == map.end()) { 
			return -1;
		} else {
			// 存在就将该元素放在最前边然后返回val
			cache.splice(cache.begin(), cache, it->second); 
			// 将cache中迭代器it->second指向的元素接在cache.begin()的位置，并释放it->second指向的元素
			return it->second->second;
		} 
	}
    
    	void put(int key, int value) {
        	// 首先查找cache中存在key吗
		unordered_map<int, list<pair<int, int> >::iterator >::iterator it = map.find(key);
		if (it != map.end()) { // 存在
			cache.erase(it->second);
		} 
		if (cache.size() == cap) { // cache已经满了
			// 删除最后一个元素
			int k = cache.rbegin()->first; // rbegin是一个逆序迭代器,返回容器的最后一个元素
			cache.pop_back();
			map.erase(k);
		}
		// 将新的node放在最前边
		cache.push_front(make_pair(key, value));
		map[key] = cache.begin();
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */ 

int main()
{
	return 0;
}
