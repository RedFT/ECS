#ifndef __MN_SCENE_H__
#define __MN_SCENE_H__

/* mn_scene.h -- the scene manager */

#include "mn_manager.h"
#include "ss_event.h"



CLASS_EXT(SceneManager, Manager,
    EventSubsystem event_ssys;
)


void SceneManager_init(void *_self);
void SceneManager_clean(void *_self);
void SceneManager_update(void *_self, double sf);
void SceneManager_registerApp(void *_self, App *app);

#endif /* __MN_SCENE_H__ */

