#include "shape_cache.h"

#include <assert.h>

int main()
{
	assert(Shape_Cache_Can_Store(1024U, 900U, 123U));
	assert(Shape_Cache_Can_Store(1024U, 900U, 124U));
	assert(!Shape_Cache_Can_Store(1024U, 900U, 125U));
	assert(!Shape_Cache_Can_Store(1024U, 1025U, 0U));
	return 0;
}
