#ifndef FOUNDATIONS_COLLECTIONS_PRIV_TYPES_H_
#define FOUNDATIONS_COLLECTIONS_PRIV_TYPES_H_ 1


#ifndef KVPAIR_DEFINED
// Define the kvpair structure
struct kvpair {
    char *key;
    char *value;
};

typedef struct kvpair kvpair_t;
size_t static_kvpair_size(){
    return (size_t)(sizeof(char *) + sizeof(char *));
}
#define KVPAIR_DEFINED 1
#endif

#endif
