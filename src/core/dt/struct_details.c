#include "../../../include/core/dt/struct_details.h"
#include <string.h>
#include <stdlib.h>

struct _struct_details {
    char *_name;            // Name of the struct
    int _memberCount;       // Count of the member variables of the structure
    size_t *_sizeArray;     // Array representing the size of each member variable
    char **_memberNames;    // Array representing the names of each member variable
    char **_memberTypes;    // Array representing the data types of each member variable
    int *_memberOffsets;    // Array representing the byte offsets of each member variable
    size_t _totalSize;      // Total size of the structure in bytes
    int _alignment;         // Alignment requirement of the structure
    bool _isPacked;         // Flag indicating whether the structure is packed or not
};

// Function to allocate memory for a struct_details object
struct_details *struct_details_empty_malloc() {
    struct_details *details = (struct_details *)malloc(sizeof(struct_details));
    if (details == NULL) {
        return NULL; // Allocation failed
    }

    // Initialize members to default values
    details->_name = NULL;
    details->_memberCount = 0;
    details->_sizeArray = NULL;
    details->_memberNames = NULL;
    details->_memberTypes = NULL;
    details->_memberOffsets = NULL;
    details->_totalSize = 0;
    details->_alignment = 0;
    details->_isPacked = false;

    return details;
}

// Parameterized constructor for struct_details
struct_details *struct_details_create(const char *name, int memberCount, const size_t *sizeArray, char **memberNames, char **memberTypes, const int *memberOffsets, size_t totalSize, int alignment, bool isPacked) {
    struct_details *details = (struct_details *)malloc(sizeof(struct_details));
    if (details == NULL) {
        return NULL; // Allocation failed
    }

    // Allocate memory for name and copy it
    details->_name = strdup(name);
    if (details->_name == NULL) {
        free(details);
        return NULL; // Allocation failed
    }

    // Allocate memory for sizeArray and copy values
    details->_sizeArray = (size_t *)malloc(memberCount * sizeof(size_t));
    if (details->_sizeArray == NULL) {
        free(details->_name);
        free(details);
        return NULL; // Allocation failed
    }
    memcpy(details->_sizeArray, sizeArray, memberCount * sizeof(size_t));

    // Allocate memory for memberNames and copy values
    details->_memberNames = (char **)malloc(memberCount * sizeof(char *));
    if (details->_memberNames == NULL) {
        free(details->_name);
        free(details->_sizeArray);
        free(details);
        return NULL; // Allocation failed
    }
    for (int i = 0; i < memberCount; ++i) {
        details->_memberNames[i] = strdup(memberNames[i]);
        if (details->_memberNames[i] == NULL) {
            // Allocation failed, free previously allocated memory
            for (int j = 0; j < i; ++j) {
                free(details->_memberNames[j]);
            }
            free(details->_memberNames);
            free(details->_name);
            free(details->_sizeArray);
            free(details);
            return NULL;
        }
    }

    // Allocate memory for memberTypes and copy values
    details->_memberTypes = (char **)malloc(memberCount * sizeof(char *));
    if (details->_memberTypes == NULL) {
        // Allocation failed, free previously allocated memory
        for (int i = 0; i < memberCount; ++i) {
            free(details->_memberNames[i]);
        }
        free(details->_memberNames);
        free(details->_name);
        free(details->_sizeArray);
        free(details);
        return NULL;
    }
    for (int i = 0; i < memberCount; ++i) {
        details->_memberTypes[i] = strdup(memberTypes[i]);
        if (details->_memberTypes[i] == NULL) {
            // Allocation failed, free previously allocated memory
            for (int j = 0; j < i; ++j) {
                free(details->_memberNames[j]);
                free(details->_memberTypes[j]);
            }
            free(details->_memberNames);
            free(details->_memberTypes);
            free(details->_name);
            free(details->_sizeArray);
            free(details);
            return NULL;
        }
    }

    // Allocate memory for memberOffsets and copy values
    details->_memberOffsets = (int *)malloc(memberCount * sizeof(int));
    if (details->_memberOffsets == NULL) {
        // Allocation failed, free previously allocated memory
        for (int i = 0; i < memberCount; ++i) {
            free(details->_memberNames[i]);
            free(details->_memberTypes[i]);
        }
        free(details->_memberNames);
        free(details->_memberTypes);
        free(details->_name);
        free(details->_sizeArray);
        free(details);
        return NULL;
    }
    memcpy(details->_memberOffsets, memberOffsets, memberCount * sizeof(int));

    // Assign other member values
    details->_memberCount = memberCount;
    details->_totalSize = totalSize;
    details->_alignment = alignment;
    details->_isPacked = isPacked;

    return details;
}

// Function to deallocate memory for a struct_details object
void struct_details_free(struct_details *details) {
    if (details == NULL) {
        return; // Nothing to free
    }

    // Free dynamically allocated members
    free(details->_name);
    free(details->_sizeArray);
    if (details->_memberNames != NULL) {
        for (int i = 0; i < details->_memberCount; ++i) {
            free(details->_memberNames[i]);
        }
        free(details->_memberNames);
    }
    if (details->_memberTypes != NULL) {
        for (int i = 0; i < details->_memberCount; ++i) {
            free(details->_memberTypes[i]);
        }
        free(details->_memberTypes);
    }
    free(details->_memberOffsets);

    // Free the struct_details object itself
    free(details);
}

// Getter function for _name
char *struct_details_getStructName(const struct_details *details) {
    return details->_name;
}

// Getter function for _memberCount
int struct_details_getMemberCount(const struct_details *details) {
    return details->_memberCount;
}

// Getter function for _sizeArray
size_t *struct_details_getSizeArray(const struct_details *details) {
    return details->_sizeArray;
}

// Getter function for _memberNames
char **struct_details_getMemberNames(const struct_details *details) {
    return details->_memberNames;
}

// Getter function for _memberTypes
char **struct_details_getMemberTypes(const struct_details *details) {
    return details->_memberTypes;
}

// Getter function for _memberOffsets
int *struct_details_getMemberOffsets(const struct_details *details) {
    return details->_memberOffsets;
}

// Getter function for _totalSize
size_t struct_details_getTotalSize(const struct_details *details) {
    return details->_totalSize;
}

// Getter function for _alignment
int struct_details_getAlignment(const struct_details *details) {
    return details->_alignment;
}

// Getter function for _isPacked
bool struct_details_isPacked(const struct_details *details) {
    return details->_isPacked;
}


// Setter function for _name
void struct_details_setStructName(struct_details *details, const char *name) {
    details->_name = strdup(name);
}

// Setter function for _memberCount (Note: _memberCount should not be modified externally)
// Setter function for _sizeArray
void struct_details_setSizeArray(struct_details *details, const size_t *sizeArray, int memberCount) {
    for (int i = 0; i < memberCount; ++i) {
        details->_sizeArray[i] = sizeArray[i];
    }
}

// Setter function for _memberNames
void struct_details_setMemberNames(struct_details *details, char **memberNames, int memberCount) {
    for (int i = 0; i < memberCount; ++i) {
        details->_memberNames[i] = strdup(memberNames[i]);
    }
}

// Setter function for _memberTypes
void struct_details_setMemberTypes(struct_details *details, char **memberTypes, int memberCount) {
    for (int i = 0; i < memberCount; ++i) {
        details->_memberTypes[i] = strdup(memberTypes[i]);
    }
}

// Setter function for _memberOffstruct_details_sets
void struct_details_setMemberOffsets(struct_details *details, const int *memberOffsets, int memberCount) {
    for (int i = 0; i < memberCount; ++i) {
        details->_memberOffsets[i] = memberOffsets[i];
    }
}

// Setter function for _totalSize
void struct_details_setTotalSize(struct_details *details, size_t totalSize) {
    details->_totalSize = totalSize;
}

// Setter function for _alignment
void struct_details_setAlignment(struct_details *details, int alignment) {
    details->_alignment = alignment;
}

// Setter function for _isPacked
void struct_details_setIsPacked(struct_details *details, bool isPacked) {
    details->_isPacked = isPacked;
}
