/*
    Copyright (c) 2006-2013, Alexis Royer, http://alexis.royer.free.fr/CLI

    All rights reserved.

    Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

        * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
        * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation
          and/or other materials provided with the distribution.
        * Neither the name of the CLI library project nor the names of its contributors may be used to endorse or promote products derived from this software
          without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
    A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
    CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
    EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
    PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
    PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
    LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#include "cli/pch.h"

#include "cli/ui_int.h"

#include "cli_ui_Int.h"

#include "NativeObject.h"
#include "NativeExec.h"
#include "NativeTraces.h"


extern "C" JNIEXPORT jint JNICALL Java_cli_ui_Int__1_1Int(
        JNIEnv* PJ_Env, jclass PJ_Class,
        jint I_NativeParentContextRef, jint I_DefaultValue, jint I_MinValue, jint I_MaxValue)
{
    NativeExec::GetInstance().RegJNIEnv(PJ_Env);

    cli::GetTraces().Trace(TRACE_JNI) << NativeTraces::Begin("ui.Int.__Int(I_NativeParentContextRef, I_DefaultValue, I_MinValue, I_MaxValue)") << cli::endl;
    cli::GetTraces().Trace(TRACE_JNI) << NativeTraces::ParamInt("I_NativeParentContextRef", I_NativeParentContextRef) << cli::endl;
    cli::GetTraces().Trace(TRACE_JNI) << NativeTraces::ParamInt("I_DefaultValue", I_DefaultValue) << cli::endl;
    cli::GetTraces().Trace(TRACE_JNI) << NativeTraces::ParamInt("I_MinValue", I_MinValue) << cli::endl;
    cli::GetTraces().Trace(TRACE_JNI) << NativeTraces::ParamInt("I_MaxValue", I_MaxValue) << cli::endl;
    NativeObject::REF i_IntRef = 0;
    cli::ui::Int* pcli_Int = NULL;
    if (I_NativeParentContextRef != 0)
    {
        if (cli::ExecutionContext* const pcli_ParentContext = NativeObject::GetNativeObject<cli::ExecutionContext*>(I_NativeParentContextRef))
        {
            pcli_Int = new cli::ui::Int(*pcli_ParentContext, I_DefaultValue, I_MinValue, I_MaxValue);
        }
    }
    else
    {
        pcli_Int = new cli::ui::Int(I_DefaultValue, I_MinValue, I_MaxValue);
    }
    if (pcli_Int != NULL)
    {
        NativeObject::Use(*pcli_Int);
        i_IntRef = NativeObject::GetNativeRef(*pcli_Int);
    }
    cli::GetTraces().Trace(TRACE_JNI) << NativeTraces::EndInt("ui.Int.__Int()", i_IntRef) << cli::endl;
    return i_IntRef;
}

extern "C" JNIEXPORT jint JNICALL Java_cli_ui_Int__1_1getInt(
        JNIEnv* PJ_Env, jclass PJ_Class,
        jint I_NativeIntRef)
{
    NativeExec::GetInstance().RegJNIEnv(PJ_Env);

    cli::GetTraces().Trace(TRACE_JNI) << NativeTraces::Begin("ui.Int.__getInt(I_NativeIntRef)") << cli::endl;
    cli::GetTraces().Trace(TRACE_JNI) << NativeTraces::ParamInt("I_NativeIntRef", I_NativeIntRef) << cli::endl;
    int i_Int = 0;
    if (const cli::ui::Int* const pcli_Int = NativeObject::GetNativeObject<const cli::ui::Int*>(I_NativeIntRef))
    {
        i_Int = pcli_Int->GetInt();
    }
    cli::GetTraces().Trace(TRACE_JNI) << NativeTraces::EndInt("ui.Int.__getInt()", i_Int) << cli::endl;
    return i_Int;
}
