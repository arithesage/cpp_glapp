#include <VertexBufferObject.hpp>

#include <GL/gl.h>

VertexBufferObject::VertexBufferObject (String attributeName,
                                        int componentCount,
                                        bool storesStaticData)
{
    this->attributeName = attributeName;
    this->componentCount = componentCount;
    this->storesStaticData = storesStaticData;        
}


void VertexBufferObject::Activate ()
{
    glBindBuffer (GL_ARRAY_BUFFER, id);
}



ColorsVBO VertexBufferObject::AsColorData ()
{
    if (this instanceof ColorsVBO) {
        return (ColorsVBO)this;
    }

    return nullptr;
}


FloatVBO VertexBufferObject::AsFloatVBO ()
{
    if (this instanceof FloatVBO) {
        return (FloatVBO)this;
    }

    return nullptr;
}


IntVBO VertexBufferObject::AsIntVBO ()
{
    if (this instanceof IntVBO) {
        return (IntVBO)this;
    }

    return nullptr;
}


VertexCoordinatesVBO VertexBufferObject::AsGeometryData ()
{
    if (this instanceof VertexCoordinatesVBO) {
        return (VertexCoordinatesVBO)this;
    }

    return nullptr;
}


VertexCoordinatesVBO VertexBufferObject::AsGeometryData ()
{
    if (this instanceof VertexCoordinatesVBO) {
        return (VertexCoordinatesVBO)this;
    }

    return nullptr;
}


String VertexBufferObject::AttributeName ()
{
    return attributeName;
}


int VertexBufferObject::AttributeIndex ()
{
    return attributeIndex;
}


int VertexBufferObject::ComponentCount ()
{
    return componentCount;
}


void VertexBufferObject::Delete ()
{
    glDeleteBuffers (id);
    id = -1;
    ready = false;
}


void VertexBufferObject:: Prepare ()
{
    if (this->HasData()) {
        if (ready) {
            Delete ();
        }

        id = glGenBuffers ();
        this->Activate();

        if (storesStaticData) {
            storageLocation = GL_STATIC_DRAW;

        } else {
            storageLocation = GL_DYNAMIC_DRAW;
        }

        UploadToVRAM();
        
        ready = true;
    }
}


bool VertexBufferObject::HasPreferredAttributeIndex ()
{
    return (attributeIndex != -1);
}


void VertexBufferObject::SetName (String name)
{
    this->attributeName = name;
}
