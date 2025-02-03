#ifndef __FLOAT_VBO__
#define __FLOAT_VBO__

#include <VertexBufferObject.hpp>


/**
 * An attribute (Vertex Buffer Object) containing float data.
 */
class FloatVBO : public VertexBufferObject
{
    private:
        List<float> data;

    public:
        /**
         * Creates a new attribute
         * 
         * @param attributeName Attribute name
         * 
         * @param componentCount How many components does this
         *                       attribute have (for example, 
         *                       a color attribute has 4 components
         *                       (r,g,b,a)).
         * 
         * @param storesStaticData False if the data is not going to
         *                         change frequently.
         */
        FloatVBO (String attributeName,
                  int componentCount,
                  bool storesStaticData);

        
        /**
         * Creates a new attribute
         * 
         * @param attributeName Attribute name
         * 
         * @param componentCount How many components does this
         *                       attribute have (for example, 
         *                       a color attribute has 4 components
         *                       (r,g,b,a)).
         * 
         * @param storesStaticData False if the data is not going to
         *                         change frequently.
         * 
         * @param data A list of floats
         */
        FloatVBO (String attributeName,
                  int componentCount,
                  bool storesStaticData,
                  List<float> data);


        /**
         * Creates a new attribute
         * 
         * @param attributeName Attribute name
         * 
         * @param componentCount How many components does this
         *                       attribute have (for example, 
         *                       a color attribute has 4 components
         *                       (r,g,b,a)).
         * 
         * @param storesStaticData False if the data is not going to
         *                         change frequently.
         * 
         * @param data A float array
         */
        FloatVBO (String attributeName,
                  int componentCount,
                  bool storesStaticData,
                  float[] data);


        /**
         * Add some data
         * @param data
         */
        void AddData (float data);


        /**
         * Add a bunch of data
         * @param data
         */
        void AddData (float... data);


        /**
         * Add a bunch of data
         * @param data
         */
        void AddData (List<float> data);


        /**
         * Returns all this attribute data.
         * Use this function for editing.
         * 
         * @return
         */
        List<float> Data ();


        /**
         * Returns all this attribute data.
         * 
         * If you want to edit, call Data instead, because the
         * FloatVBO stores its data in a float list and this
         * function creates a float array from that list.
         * 
         * @return the VBO data in array form.
         */
        float[] DataArray ();


        bool HasData () override;


        /**
         * Sets all needed data
         * @param data
         */
        void SetData (float[] data);


        /**
         * Sets all needed data
         * @param data
         */
        void SetData (List<float> data);

        
        /**
         * Returns the stride for this attribute type.
         * In this case, the stride is Float size / number of components.
         * 
         * Float size is divided by 8 because SIZE returns the type size
         * in bits instead of bytes. 
         */
        int Stride () override;

        
        /**
         * Uploads the data to the GPU
         */
        void UploadToVRAM () override;
};

#endif