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

#include "cli/traces.h"
#include "cli/io_device.h"


// Outern declarations.
const bool CheckGetLine(void);
const bool CheckGetPassword(void);
const bool CheckGetInt(void);
const bool CheckGetFloat(void);
const bool CheckYesNoQuestion(void);
const bool CheckChoiceQuestion(void);
const bool CheckMore(void);
const bool CheckLess(void);


// Main function.
int main(void)
{
    cli::GetTraces().SetStream(cli::OutputDevice::GetStdErr());

    bool b_Res = true;
    b_Res = b_Res && CheckGetLine();
    b_Res = b_Res && CheckGetPassword();
    b_Res = b_Res && CheckGetInt();
    b_Res = b_Res && CheckGetFloat();
    b_Res = b_Res && CheckYesNoQuestion();
    b_Res = b_Res && CheckChoiceQuestion();
    b_Res = b_Res && CheckMore();
    b_Res = b_Res && CheckLess();

    cli::GetTraces().UnsetStream(cli::OutputDevice::GetStdErr());

    return (b_Res ? 0 : -1);
}
