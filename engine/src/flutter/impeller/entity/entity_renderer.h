// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include "flutter/fml/macros.h"
#include "impeller/compositor/renderer.h"
#include "impeller/compositor/vertex_buffer.h"
#include "impeller/entity/entity.h"
#include "impeller/primitives/box_primitive.h"

namespace impeller {

class EntityRenderer final : public Renderer {
 public:
  EntityRenderer(std::string shaders_directory);

  ~EntityRenderer() override;

 private:
  std::shared_ptr<Entity> root_;
  std::shared_ptr<BoxPrimitive> box_primitive_;
  VertexBuffer vertex_buffer_;
  bool is_valid_ = false;

  // |Renderer|
  bool OnIsValid() const override;

  // |Renderer|
  bool OnRender(const Surface& surface, RenderPass& pass) override;

  FML_DISALLOW_COPY_AND_ASSIGN(EntityRenderer);
};

}  // namespace impeller
