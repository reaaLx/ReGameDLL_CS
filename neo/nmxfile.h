/* Reconstructed from the engine's DWARF debug info (engine_i486.so).
   Struct layouts and member order are exact. #define values, comments and the
   lump index order are NOT in the debug info and are not included. */
#ifndef NMXFILE_H_RECONSTRUCTED
#define NMXFILE_H_RECONSTRUCTED

/* NmxFileBoneWeight: 8 bytes */
typedef struct {
    int node_id;   /* +0 */
    float value;   /* +4 */
} NmxFileBoneWeight;

/* NmxFileBone: 192 bytes */
typedef struct {
    int node_id;   /* +0 */
    int type;   /* +4 */
    float mass;   /* +8 */
    float velocity;   /* +12 */
    int gravity_type;   /* +16 */
    float gravity;   /* +20 */
    int wind_type;   /* +24 */
    float wind;   /* +28 */
    float angleminmax_yaw[2];   /* +32 */
    float angleminmax_pitch[2];   /* +40 */
    char collisions[4][32];   /* +48 */
    int connections[4];   /* +176 */
} NmxFileBone;

/* NmxFileCollision: 92 bytes */
typedef struct {
    char name[32];   /* +0 */
    int primitive;   /* +32 */
    float center[3];   /* +36 */
    float r[3];   /* +48 */
    float s[3];   /* +60 */
    float t[3];   /* +72 */
    int firstBoneWeight;   /* +84 */
    int numBoneWeights;   /* +88 */
} NmxFileCollision;

/* NmxFileFXPropertiesLump: 20 bytes */
typedef struct {
    int numProperties;   /* +0 */
    int dataofs[4];   /* +4 */
} NmxFileFXPropertiesLump;

/* NmxFileFXProperty: 132 bytes */
typedef struct {
    char name[128];   /* +0 */
    short type;   /* +128 */
    short size;   /* +130 */
} NmxFileFXProperty;

/* NmxFileFXShader: 132 bytes */
typedef struct {
    char name[128];   /* +0 */
    int technique;   /* +128 */
} NmxFileFXShader;

/* NmxFileHeader: 132 bytes */
typedef struct {
    int version;   /* +0 */
    int fileofs;   /* +0 */
    int filelen;   /* +4 */
} NmxFileHeader;

/* NmxFileMesh1002: 36 bytes */
typedef struct {
    int flags;   /* +0 */
    int firstTexture;   /* +4 */
    int numTextures;   /* +8 */
    int firstTangent;   /* +12 */
    int numTangents;   /* +16 */
    int firstBinormal;   /* +20 */
    int numBinormals;   /* +24 */
    float kBump;   /* +28 */
    float specularExponent;   /* +32 */
} NmxFileMesh1002;

/* NmxFileMesh1003: 48 bytes */
typedef struct {
    int flags;   /* +0 */
    int firstTexture;   /* +4 */
    int numTextures;   /* +8 */
    int firstTangent;   /* +12 */
    int numTangents;   /* +16 */
    int firstBinormal;   /* +20 */
    int numBinormals;   /* +24 */
    float kBump;   /* +28 */
    float specularExponent;   /* +32 */
    int fxshader;   /* +36 */
    int firstfxproperty;   /* +40 */
    int numfxproperties;   /* +44 */
} NmxFileMesh1003;

/* NmxFileMesh: 28 bytes */
typedef struct {
    int flags;   /* +0 */
    int firstTexture;   /* +4 */
    int numTextures;   /* +8 */
    int firstTangent;   /* +12 */
    int numTangents;   /* +16 */
    int firstBinormal;   /* +20 */
    int numBinormals;   /* +24 */
} NmxFileMesh;

/* NmxFileModel1003: 56 bytes */
typedef struct {
    char name[32];   /* +0 */
    int firstMesh;   /* +32 */
    int numMeshes;   /* +36 */
    int firstVertex;   /* +40 */
    int numVertexes;   /* +44 */
    int firstPostEffect;   /* +48 */
    int numPostEffects;   /* +52 */
} NmxFileModel1003;

/* NmxFileModel: 48 bytes */
typedef struct {
    char name[32];   /* +0 */
    int firstMesh;   /* +32 */
    int numMeshes;   /* +36 */
    int firstVertex;   /* +40 */
    int numVertexes;   /* +44 */
} NmxFileModel;

/* NmxFilePostEffect: 12 bytes */
typedef struct {
    int fxshader;   /* +0 */
    int firstfxproperty;   /* +4 */
    int numfxproperties;   /* +8 */
} NmxFilePostEffect;

/* NmxFileTexture: 64 bytes */
typedef struct {
    char semantics[32];   /* +0 */
    char name[32];   /* +32 */
} NmxFileTexture;

/* NmxFileVertex: 8 bytes */
typedef struct {
    int firstBoneWeight;   /* +0 */
    int numBoneWeights;   /* +4 */
} NmxFileVertex;

/* ---- Lump table ----
   The header is: int version, then 16 lump_t { int offset; int length } pairs at
   byte 4 + 8*i. Lump index i is taken from CNeoStudioModelLoader::read(), where
   each load*(lump_t*) receives header + 4 + 8*i (engine_amd.so, 0x003ded28).
   Lumps 0-6 were checked against v_ak47_nm.nmx (version 1000). Lumps 7-13 come
   from the call displacements only and are not checked against a file.
   Lumps 3 and 6 depend on the version (see the loader list below). */
typedef enum {
    NMX_LUMP_TANGENT          = 0,   /* loadTangent: vec3[]. v_ak47: 3983 entries */
    NMX_LUMP_BINORMAL         = 1,   /* loadBinormal: vec3[]. v_ak47: 3983 entries */
    NMX_LUMP_TEXTURE          = 2,   /* loadTexture: NmxFileTexture[]. v_ak47: 6 entries */
    NMX_LUMP_MESH             = 3,   /* loadMesh (v1000), loadMesh1002, loadMesh1003: NmxFileMesh[]. v_ak47: 2 entries */
    NMX_LUMP_BONEWEIGHT       = 4,   /* loadBoneWeight: NmxFileBoneWeight[]. v_ak47: 1553 entries */
    NMX_LUMP_VERTEX           = 5,   /* loadVertex: NmxFileVertex[]. v_ak47: 1553 entries */
    NMX_LUMP_MODEL            = 6,   /* loadSubmodel1003 (v1000), loadSubmodel1004, loadSubmodel: NmxFileModel[]. v_ak47: 1 entry */
    NMX_LUMP_BONE             = 7,   /* loadBone: NmxFileBone[] (code only) */
    NMX_LUMP_COLLISION        = 8,   /* loadCollision: NmxFileCollision[] (code only) */
    NMX_LUMP_FXSHADER         = 9,   /* loadFXShader (code only) */
    NMX_LUMP_FXPROPERTIES     = 10,  /* loadFXProperties (code only) */
    NMX_LUMP_POSTEFFECT       = 11,  /* loadPostEffect: NmxFilePostEffect[] (code only) */
    NMX_LUMP_ATTACHMENT_MODEL = 12,  /* loadAttachmentModel (code only) */
    NMX_LUMP_ATTACHMENT_BONE  = 13,  /* loadAttachmentBoneTweak (code only) */
    NMX_LUMP_COUNT            = 16   /* header has 16 lump slots; 14-15 are unused in v1000 */
} NmxLump;

/* Version-dependent loader choice, from the version compares in read():
     1000 and 1001 (fall-through path, version <= 1001):
            lump 3 -> loadMesh, lump 6 -> loadSubmodel1003
     1002:  lump 3 -> loadMesh1002, lump 6 -> loadSubmodel (path taken when version > 1001)
     1003+: lump 3 -> loadMesh1003 (path taken when version > 1002)
   Only the 1000 path is checked against a file. The 1002 and 1003+ mappings
   follow the cmp chain in read() and are not tested. */

#endif
