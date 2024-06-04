#ifndef HASHMAP_H
#define HASHMAP_H

#include <vector>
#include <QDebug>

template <class K, class V>
class HashMap
{
public:
    HashMap();

    void put(K key, V value);
    V get(K key);

private:
    struct Node {
        K key;
        V value;
    };

    int size = 0;
    std::vector<std::vector<Node>> buckets;

    const int INITIAL_CAPACITY = 16;
    const float LOAD_FACTOR = 0.75f;

    int hash(K key);
    void resize();

    friend QDebug operator<<(QDebug debug, HashMap<K, V> &map) {
        for (auto bucket : map.buckets) {
            for (auto n : bucket) {
                debug << n.key << ":" << n.value;
            }
        }

        return debug;
    }
};

template <class K, class V>
HashMap<K, V>::HashMap() {
    for (int i = 0; i < INITIAL_CAPACITY; i++) {
        buckets.push_back({});
    }
}

template <class K, class V>
void HashMap<K, V>::put(K key, V value) {
    int bucketIdx = hash(key);
    std::vector bucket = buckets[bucketIdx];

    for (Node n : bucket) {
        if (n.key == key) {
            n.value = value;
            return;
        }
    }

    buckets[bucketIdx].push_back(Node {.key = key, .value = value});
    size++;

    if (((float)size / (float)buckets.size()) >= LOAD_FACTOR)
        resize();
}

template <class K, class V>
V HashMap<K, V>::get(K key) {
    std::vector bucket = buckets[hash(key)];

    for (Node n : bucket)
        if (n.key == key)
            return n.value;

    return NULL;
}

template <class K, class V>
int HashMap<K, V>::hash(K key) {
    int a = buckets.size();
    return std::hash<K>{}(key) % buckets.size();
}

template <class K, class V>
void HashMap<K, V>::resize() {
    int newCapacity = buckets.size() * 2;
    std::vector<std::vector<Node>> newBuckets;

    for (int i = 0; i < newCapacity; i++) {
        newBuckets.push_back({});
    }

    for (std::vector<Node> bucket : buckets) {
        for (Node n : bucket) {
            int newBucketIdx = std::hash<K>{}(n.key) % newCapacity;
            newBuckets[newBucketIdx].push_back(n);
        }
    }

    buckets = newBuckets;
}


#endif // HASHMAP_H
