//=======================================================================================
// Copyright (c) 2001-2017 Agog Labs Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=======================================================================================

//=======================================================================================
// SkookumScript Plugin for Unreal Engine 4
//
// SkookumScript MulticastDelegate (= FMulticastScriptDelegate) class
//=======================================================================================

#pragma once

//=======================================================================================
// Includes
//=======================================================================================

#include "UObject/WeakObjectPtr.h"

#include <SkookumScript/SkClassBinding.hpp>

//---------------------------------------------------------------------------------------
// SkookumScript MulticastDelegate (= FMulticastScriptDelegate) class
class SKOOKUMSCRIPTRUNTIME_API SkUEMulticastDelegate : public SkClassBindingSimple<SkUEMulticastDelegate, FMulticastScriptDelegate>
  {
  public:

    static void         register_bindings();
    static SkClass *    get_class();
    static SkInstance * new_instance(const FMulticastScriptDelegate & script_delegate);

  protected:

    //---------------------------------------------------------------------------------------
    // Special flavor of SkInstance that handles invocation of ScriptDelegates
    class Instance : public SkInstance
      {
      public:
      
        // Empty constructor for vtable stamping
        Instance(eALeaveMemoryUnchanged) : SkInstance(ALeaveMemoryUnchanged) {}

        // This is an invokable instance
        virtual eSkObjectType get_obj_type() const override { return SkObjectType_invokable; }

        // Destructor
        virtual void delete_this() override;

        // Invoke the ScriptDelegate represented by this SkInstance
        virtual void invoke_as_method(
          SkObjectBase * scope_p,
          SkInvokedBase * caller_p,
          SkInstance ** result_pp,
          const SkClosureInvokeInfo & invoke_info,
          const SkExpressionBase * invoking_expr_p) const override;
      };

  };

//=======================================================================================
// Inline Function Definitions
//=======================================================================================

//---------------------------------------------------------------------------------------

inline SkInstance * SkUEMulticastDelegate::new_instance(const FMulticastScriptDelegate & script_delegate)
  {
  // Create an instance the usual way
  SkInstance * instance_p = SkClassBindingSimple<SkUEMulticastDelegate, FMulticastScriptDelegate>::new_instance(script_delegate);

  // Then change v-table to SkUEScriptDelegate::Instance
  new (instance_p) Instance(ALeaveMemoryUnchanged);

  return instance_p;
  }
