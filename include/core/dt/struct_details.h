#ifndef FOUNDATIONS_CORE_DT_STRUCT_DETAILS_H_
#define FOUNDATIONS_CORE_DT_STRUCT_DETAILS_H_


#include <stdbool.h>
#include <stddef.h>

// Forward declaration of struct_details
typedef struct _struct_details struct_details;

struct_details *struct_details_empty_malloc();
struct_details *struct_details_create(const char *name, int memberCount, const size_t *sizeArray, char **memberNames,
                                      char **memberTypes, const int *memberOffsets, size_t totalSize, int alignment,
                                      bool isPacked);
void struct_details_free(struct_details *details);

char *struct_details_getStructName(const struct_details *details);
int struct_details_getMemberCount(const struct_details *details);
size_t *struct_details_getSizeArray(const struct_details *details);
char **struct_details_getMemberNames(const struct_details *details);
char **struct_details_getMemberTypes(const struct_details *details);
int *struct_details_getMemberOffsets(const struct_details *details);
size_t struct_details_getTotalSize(const struct_details *details);
int struct_details_getAlignment(const struct_details *details);
bool struct_details_isPacked(const struct_details *details);

void struct_details_setStructName(struct_details *details, const char *name);
void struct_details_setSizeArray(struct_details *details, const size_t *sizeArray, int memberCount);
void struct_details_setMemberNames(struct_details *details, char **memberNames, int memberCount);
void struct_details_setMemberTypes(struct_details *details, char **memberTypes, int memberCount);
void struct_details_setMemberOffsets(struct_details *details, const int *memberOffsets, int memberCount);
void struct_details_setTotalSize(struct_details *details, size_t totalSize);
void struct_details_setAlignment(struct_details *details, int alignment);
void struct_details_setIsPacked(struct_details *details, bool isPacked);


#endif
