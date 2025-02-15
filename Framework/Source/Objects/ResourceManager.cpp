#include "FrameworkPCH.h"

#include "ResourceManager.h"
#include "Utility/ShaderProgram.h"
#include "Mesh.h"
#include "Texture.h"
#include "Material.h"

namespace fw {

ResourceManager::ResourceManager()
{

}

ResourceManager::~ResourceManager()
{
    for (std::pair<std::string, ShaderProgram*> object : m_pShaders)
    {
        delete object.second;
    }

    for (std::pair<std::string, Mesh*> object : m_pMeshes)
    {
        delete object.second;
    }

    for (std::pair<std::string, Texture*> object : m_pTextures)
    {
        delete object.second;
    }

    for (std::pair<std::string, Material*> object : m_pMaterials)
    {
        delete object.second;
    }
}

void ResourceManager::AddShader(const char* name, ShaderProgram* pShader)
{
    m_pShaders[name] = pShader;

}

void ResourceManager::AddShader(const char* name, const char* vertFilename, const char* fragFilename)
{
    ShaderProgram* temp = new ShaderProgram(vertFilename, fragFilename);
    AddShader(name, temp);
}

void ResourceManager::AddMesh(const char* name, Mesh* pMesh)
{
    m_pMeshes[name] = pMesh;
}

void ResourceManager::AddMesh(const char* name, int primitiveType, int numVertices, const VertexFormat* pVertices)
{
    Mesh* temp = new Mesh(primitiveType, numVertices, pVertices);
    AddMesh(name, temp);
}

void ResourceManager::AddTexture(const char* name, Texture* pTexture)
{
    m_pTextures[name] = pTexture;
}

void ResourceManager::AddTexture(const char* name, const char* filename)
{
    Texture* temp = new Texture(filename);
    AddTexture(name, temp);
}

void ResourceManager::AddMaterial(const char* name, Material* pMaterial)
{
    m_pMaterials[name] = pMaterial;
}

void ResourceManager::AddMaterial(const char* name, ShaderProgram* pShaderProgram, Texture* pTexture, Color pColor, vec2 m_UVScale, vec2 pUVOffset)
{
    Material* temp = new Material(pShaderProgram, pTexture, pColor, m_UVScale, pUVOffset);
    AddMaterial(name, temp);
}

std::string ResourceManager::FindTextureName(Texture* pTexture)
{
    for(auto& it = m_pTextures.begin(); it != m_pTextures.end(); it++)
    {
        if(it->second == pTexture)
        {
            return it->first;
        }
    }

    return "Texture not found";
}

} // namespace fw
