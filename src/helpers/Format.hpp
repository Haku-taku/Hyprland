#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <GLES3/gl32.h>
#include "math/Math.hpp"
#include <aquamarine/backend/Misc.hpp>

using DRMFormat = uint32_t;
using SHMFormat = uint32_t;

using SDRMFormat = Aquamarine::SDRMFormat;

namespace NFormatUtils {
    SHMFormat   drmToShm(DRMFormat drm);
    DRMFormat   shmToDRM(SHMFormat shm);
    bool        isFormatYUV(uint32_t drmFormat);
    /// Whether a DRM format carries more than eight bits per channel: the packed
    /// ten-bit RGB layouts, in either channel order.
    bool        is10BitFormat(DRMFormat drmFormat);
    bool        isShmBufferLayoutValid(DRMFormat drmFormat, const Vector2D& size, int32_t stride, int32_t offset, size_t poolSize);
    std::string drmFormatName(DRMFormat drm);
    std::string drmModifierName(uint64_t mod);
    DRMFormat   alphaFormat(DRMFormat prevFormat);
};
