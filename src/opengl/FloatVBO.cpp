#include <FloatVBO.hpp>


FloatVBO::FloatVBO (String attributeName,
                    int componentCount,
                    bool storesStaticData) 
                    : VertexBufferObject (attributeName, 
                                          componentCount, 
                                          storesStaticData)
{
    
}


FloatVBO::FloatVBO (String attributeName,
                    int componentCount,
                    bool storesStaticData,
                    List<float> data)
                    : VertexBufferObject (attributeName, 
                                          componentCount, 
                                          storesStaticData)
{
    this->data = data;
}



FloatVBO::FloatVBO (String attributeName,
                    int componentCount,
                    bool storesStaticData,
                    float[] data)
                    : VertexBufferObject (attributeName,
                                          componentCount, 
                                          storesStaticData)
{
    this->data = List<float>(data);
    AddData (data);
}


void FloatVBO::AddData (float data)
{
    this->data.add (Float.valueOf(data));
}


void FloatVBO::AddData (float... data)
{
    for (float value : data)
    {
        this->data.add (Float.valueOf(value));
    }
}


void FloatVBO::AddData (List<float> data)
{
    this->data.addAll (data);
}


List<float> FloatVBO::Data ()
{
    return data;
}


float[] FloatVBO::DataArray () 
{
    return CollectionsHelpers.FloatListToArray(data);
}


bool FloatVBO::HasData ()
{
    return ((data != null) && (!data.isEmpty()));
}


void FloatVBO::SetData (float[] data)
{
    this.data = CollectionsHelpers.FloatArrayToList(data);
}


void FloatVBO::SetData (List<float> data)
{
    this.data = data;
}


int FloatVBO::Stride ()
{
    if (componentCount > 0) {
        return ((Float.SIZE / 8) * componentCount);
    }

    return -1;
}


void FloatVBO::UploadToVRAM () {
    glBufferData(GL_ARRAY_BUFFER, DataArray(), storageLocation);
}
