#ifndef __VERTEX_ARRAY_OBJECT__
#define __VERTEX_ARRAY_OBJECT__

#include <GLObject.hpp>

#include <vector>

template <typename T>
using List = std::vector<T>


class VertexArrayObject : public GLObject
{
    private:
        List<VertexBufferObject> attributes = null;
};

#endif