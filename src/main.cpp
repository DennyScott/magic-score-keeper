/*
 * This file is part of the Marmalade SDK Code Samples.
 *
 * Copyright (C) 2001-2012 Ideaworks3D Ltd.
 * All Rights Reserved.
 *
 * This source code is intended only as a supplement to Ideaworks Labs
 * Development Tools and/or on-line documentation.
 *
 * THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
 * PARTICULAR PURPOSE.
 */
#include "s3e.h"
#include "IwUI.h"
#include "IwResManager.h"

// "main" is the S3E entry point
int main()
{
    IwUIInit();

    //clear to white
    IwGxSetColClear(0xff, 0xff, 0xff, 0xff);

    CIwUIView* pView = new CIwUIView;
    CIwUIController* pController = new CIwUIController;

    IwGetResManager()->LoadGroup("ui.group");

    CIwUIElement* pUI = ((CIwUIElement*)IwGetResManager()->GetResNamed("main", "CIwUIElement"))->Clone();
    pView->AddElement(pUI);
    pView->AddElementToLayout(pUI);

    // to exit correctly, applications should poll for quit requests
    while(!s3eDeviceCheckQuitRequest())
    {
        IwGxClear();

        pView->Update(20);
        pController->Update();

        pView->Render();

        IwGxFlush();
        IwGxSwapBuffers();

        // S3E applications should yield frequently
        s3eDeviceYield();
    }

    delete pController;
    delete pView;

    IwUITerminate();

    return 0;
}
