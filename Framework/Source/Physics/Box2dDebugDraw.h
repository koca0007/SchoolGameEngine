#pragma once
#include "box2d/box2d.h"

namespace fw {

class Material;
class ShaderProgram;

class Box2dDebugDraw : public b2Draw
{
public:
    Box2dDebugDraw(Material* pMaterial);
    ~Box2dDebugDraw();

    virtual void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) override;
    virtual void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) override;
    virtual void DrawCircle(const b2Vec2& center, float radius, const b2Color& color) override;
    virtual void DrawSolidCircle(const b2Vec2& center, float radius, const b2Vec2& axis, const b2Color& color) override;
    virtual void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)override;
    virtual void DrawTransform(const b2Transform& xf) override;
    virtual void DrawPoint(const b2Vec2& p, float size, const b2Color& color) override;

    //void SetViewAndProj(vec4* view, vec4* proj);

    Material* m_pMaterial;

    ShaderProgram* m_pShader;
};

} // namespace fw
