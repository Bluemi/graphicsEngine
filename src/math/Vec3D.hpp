#ifndef __VEC3D_CLASS__
#define __VEC3D_CLASS__

class Vec3D
{
	public:
		Vec3D(float, float, float);
		Vec3D();

		float getX() const;
		float getY() const;
		float getZ() const;
	private:
		float x, y, z;
};

#endif
