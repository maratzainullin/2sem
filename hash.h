#ifndef INC_2SEM_HASH_H
#define INC_2SEM_HASH_H

#define MAX_HASH 100;


namespace hash {
    template<class Key_T>
    int get_hash(Key_T key) {
        return (int) key % MAX_HASH;
    };



}
#endif //INC_2SEM_HASH_H
