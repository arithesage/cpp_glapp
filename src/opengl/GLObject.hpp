#ifndef __GL_OBJECT__
#define __GL_OBJECT__


class GLObject
{
    protected:
        int id = -1;
        bool ready = false;

    public:
        /**
         * Activates this OpenGL objects.
         * 
         * Sets this object the current enabled one of its type.
         * Here you bind VAOs, VBOs, etc...
         */
        virtual void Activate () = 0;


        /**
         * Prepares this OpenGL object for use.
         * 
         * This is the place where you create buffers, bind them, 
         * upload data to GPU VRAM...
         */
        virtual void Prepare () = 0;


        /**
         * Destroys this OpenGL object.
         * 
         * This is the place where you reset the id, destroy buffers...
         */
        virtual void Delete () = 0;


        /**
         * Returns this object ID
         */
        int Id ();


        /**
         * Returns if this object is ready for being used (properly created)
         */
        bool IsReady ();
};

#endif