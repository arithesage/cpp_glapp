#ifndef __COLORS_VBO__
#define __COLORS_VBO__

#include <FloatVBO.hpp>


/**
 * A Float Vertex Buffer Object intended for storing
 * color attributes for a mesh vertices.
 */
class ColorsVBO : public FloatVBO
{
    /**
     * Habitual colors
     */
    class Colors
    {
        public:
            static const float BLACK[];
            static const float BLUE[];
            static const float GREEN[];
            static const float RED[];
            static const float WHITE[];
    };


    public:
        /**
         * Creates a Color VBO.
         * 
         * @param attributeName Attribute name
         * 
         * @param storesStaticData False if the data is going to
         *                         change frequently.
         */
        ColorsVBO (String attributeName, bool storesStaticData);


        /**
         * Adds a new color.
         * 
         * @param r Red component.
         * @param g Green component.
         * @param b Blue component.
         * @param a Alpha component.
         */
        void AddColor (float r, float g, float b, float a);


        /**
         * Adds a new color
         * @param components An array with the four color components (r,g,b,a)
         */
        void AddColor (float[] components);


        /**
         * Adds a new color
         * @param components A list with the four color components (r,g,b,a)
         */
        void AddColor (List<float> components);


        /**
         * Returns all stored colors
         * @return a float array with r1,g1,b1,a1, r2,g2,b2,a2...
         */
        float[] Colors ();


        /**
         * Sets all colors.
         * For 
         * 
         * @param colors A float array with all color data
         *               (r1,g1,b1,a1 , r2,g2,b2,a2...)
         */
        void SetColors (float[] colors);
};

#endif