#pragma once

#include <string>
#include <array>
#include <vector>


#include "../types.h"

namespace osp
{

enum class ObjectType
{
    NONE,       // Normal old object
    MESH,       // It has a mesh
    COLLIDER//,   // It's a collider
    //ATTACHMENT  //
};

enum class ColliderType
{
    CUBE,
    CYLINDER,
    MESH

    // add more here
};

//const uint32_t gc_OBJ_MESH      = 1 << 2;
//const uint32_t gc_OBJ_COLLIDER  = 1 << 3;


struct DrawableData
{

    // index to a PrototypePart.m_meshDataUsed
    unsigned m_mesh;
    //std::string m_mesh;
    //unsigned m_material;
};

struct ColliderData
{
    ColliderType m_type;
    unsigned m_meshData;
};

struct PrototypeObject
{
    unsigned m_parentIndex;
    unsigned m_childCount;
    //unsigned m_mesh;

    uint32_t m_bitmask;

    std::string m_name;



    //Magnum::Matrix4 m_transform;
    // maybe not use magnum types here
    Magnum::Vector3 m_translation;
    Magnum::Quaternion m_rotation;
    Magnum::Vector3 m_scale;

    ObjectType m_type;

    union
    {
        DrawableData m_drawable;
        ColliderData m_collider;

    };

    // Put more OSP-specific data in here
};


struct PrototypeMachine
{
    std::string m_type;

    // TODO: some sort of data
};

/**
 * Describes everything on how to construct a part, loaded directly from a file
 * or something
 */
class PrototypePart
{

public:
    PrototypePart();

    constexpr std::vector<PrototypeObject>& get_objects()
    { return m_objects; }
    constexpr std::vector<PrototypeObject> const& get_objects() const
    { return m_objects; }


    constexpr std::vector<PrototypeMachine>& get_machines()
    { return m_machines; }
    constexpr std::vector<PrototypeMachine> const& get_machines() const
    { return m_machines; }


    constexpr std::vector<std::string>& get_strings()
    { return m_strings; }

private:
    //std::string name; use path

    std::vector<PrototypeObject> m_objects;

    std::vector<PrototypeMachine> m_machines;

    //std::vector<DependRes<MeshData3D> > m_meshDataUsed;

    // TODO: more OSP information

    // std::vector <machines>

    std::vector<std::string> m_strings;

};

}