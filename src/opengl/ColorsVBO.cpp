#include <ColorsVBO.hpp>


const float ColorsVBO::Colors::BLACK[] = { 0.0f, 0.0f, 0.0f, 1.0f };
const float ColorsVBO::Colors::BLUE[] = { 0.0f, 0.0f, 1.0f, 1.0f };
const float ColorsVBO::Colors::GREEN[] = { 0.0f, 1.0f, 0.0f, 1.0f };
const float ColorsVBO::Colors::RED[] = { 1.0f, 0.0f, 0.0f, 1.0f };
const float ColorsVBO::Colors::WHITE[] = { 1.0f, 1.0f, 1.0f, 1.0f };


ColorsVBO::ColorsVBO (String attributeName, 
                      bool storesStaticData)
                      : FloatVBO (attributeName, 4, storesStaticData);
{
    attributeIndex = 1;
}


void ColorsVBO::AddColor (float r, float g, float b, float a)
{
    AddData (r, g, b, a);
}


void ColorsVBO::AddColor (float[] components)
{
    AddData (CollectionsHelpers.FloatArrayToList(components));
}


void ColorsVBO::AddColor (List<Float> components)
{
    AddData (components);
}


float[] ColorsVBO::Colors ()
{
    return DataArray();
}


void ColorsVBO::SetColors (float[] colors)
{
    AddData (colors);
}
