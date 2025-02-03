#ifndef __VERTEX_BUFFER_OBJECT__
#define __VERTEX_BUFFER_OBJECT__

#include <GLObject.hpp>
#include <Types.hpp>


/**
 * Vertex Buffer Object.
 *
 * Stores information about one OpenGL attribute.
 *
 * 'components' refers to the number of components the data being passed has.
 *              For example: If we are passing coordinates. each one has
 *              three components (x, y and z).
 *
 * 'data_type'  refers to the type of the data components. In the above example,
 *              each one of the coordinate components would be of float type
 *              (or GL_FLOAT in this case due we are working with OpenGL).
 *              The OpenGL types are GL_BOOL, GL_FLOAT, GL_INT and GL_UINT.
 *              The default data_type is GL_FLOAT.
 *
 * 'static'     parameter determines where the data will be stored
 *              in the GPU VRAM in order to optimize things.
 *
 *              - If the data is not going to change (the vertices of a static mesh),
 *                static should be True.
 *
 *              - If the data is going to change frequently (the vertices of an animated mesh),
 *                static should be False.
 */
class VertexBufferObject : public GLObject
{
    protected:
        int attributeIndex = -1;
        String attributeName = "";
        int componentCount = 0;
        bool storesStaticData = true;
        int storageLocation = -1;

    public:
        /**
         * Creates a new VertexBufferObject (VBO)
         * 
         * @param attributeName Name of this VBO.
         * 
         * @param componentCount Number of components that the data held
         *                       by this VBO has. For example: Coordinates
         *                       has 3 components (x, y and z).
         * 
         * @param storesStaticData If the data is not going to change frequently,
         *                         it should be stored as static data, otherwise
         *                         store it as dynamic data.
         */
        VertexBufferObject (String attributeName,
                            int componentCount,
                            bool storesStaticData);


        
        void Activate () override;


        ColorsVBO AsColorData ();


        FloatVBO AsFloatVBO ();


        IntVBO AsIntVBO ();


        TextureCoordinatesVBO AsTextureData ();


        String AttributeName ();


        int AttributeIndex ();


        int ComponentCount ();


        void Delete () override;


        void Prepare () override;


        bool HasPreferredAttributeIndex ();


        virtual bool HasData () = 0;


        void SetName (String name);


        virtual int Stride () = 0;


        virtual void UploadToVRAM () = 0;
};

#endif