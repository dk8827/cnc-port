#ifndef SHAPE_CACHE_H
#define SHAPE_CACHE_H

static inline bool Shape_Cache_Can_Store(unsigned long capacity, unsigned long used, unsigned long bytes)
{
	return used <= capacity && bytes <= capacity - used;
}

#endif
