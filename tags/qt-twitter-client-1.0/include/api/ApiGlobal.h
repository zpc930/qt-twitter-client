#ifndef API_GLOBAL_H
#define API_GLOBAL_H

#define OK 0
#define FAIL 1

#define NUM_TO_BIT(id)          (1 << (id))
#define BITMAP_SET(map, id)     ((map) |= NUM_TO_BIT(id))
#define BITMAP_TEST(map, id)    ((map) & NUM_TO_BIT(id))
#define BITMAP_CLEAN(map, id)   ((map) &= ~(NUM_TO_BIT(id)))

#define API_PROVIDER_DEBUG 0

#endif // API_GLOBAL_H
