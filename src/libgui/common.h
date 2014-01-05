#ifndef _COMMON_H
#define _COMMON_H



#include <Inventor/elements/SoGLCacheContextElement.h>
#include <Inventor/actions/SoWriteAction.h>
#include <Inventor/nodes/SoComplexity.h>
#include <Inventor/nodes/SoCoordinate3.h>
#include <Inventor/nodes/SoFaceSet.h>
#include <Inventor/nodes/SoPointSet.h>
#include <Inventor/nodes/SoLightModel.h>
#include <Inventor/nodes/SoLineSet.h>
#include <Inventor/nodes/SoMaterialBinding.h>
#include <Inventor/nodes/SoTextureCombine.h>
#include <Inventor/nodes/SoTextureCoordinate2.h>
#include <Inventor/nodes/SoTextureScalePolicy.h>
#include <Inventor/nodes/SoTransparencyType.h>
#include <Inventor/misc/SoGLImage.h>
#include <Inventor/events/SoLocation2Event.h>
#include <Inventor/SoPickedPoint.h>
#include <QtOpenGL/QGLWidget>
#include <Inventor/Qt/viewers/SoQtExaminerViewer.h>
#include <Inventor/Qt/SoQt.h>
#include <Inventor/Qt/SoQtRenderArea.h>
#include <Inventor/nodes/SoCone.h>
#include <Inventor/nodes/SoDirectionalLight.h>
#include <Inventor/nodes/SoMaterial.h>
#include <Inventor/nodes/SoPerspectiveCamera.h>
#include <Inventor/nodes/SoRotationXYZ.h>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/engines/SoElapsedTime.h>
#include "ui_robotvision.h"


struct Viewer{
        //VIEWERTYPE type;
        SoQtExaminerViewer *window;
        SoSeparator *root;
        string title;
        QWidget *tab;
    Viewer(){
      window = NULL;
      root = NULL;
      title = "";
      tab = NULL;


    }
};

#endif // _COMMON_H
