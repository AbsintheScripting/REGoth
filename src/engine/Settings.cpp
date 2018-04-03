/* 
 * File:   Settings.cpp
 * Author: Migos (@AbsintheScripting)
 *
 * Created on 31. März 2018, 15:48
 */

#include "Settings.h"

Settings::Settings() {
    Settings::initStandardSettings ();
}

Settings::~Settings() {
}

void Settings::setSettingsToStandard() {
    // TODO: switch over QualityIndex and change Video-Settings
    /* Opt_Internal */
    opt_Internal_Choicebox.option["perfQualityIndex"] = 1;
    /* Opt_Game */
    opt_Game_Choicebox.option["subTitles"] = 0;
    opt_Game_Choicebox.option["highlightMeleeFocus"] = 2;
    opt_Game_Choicebox.option["highlightInteractFocus"] = 0;
    opt_Game_Choicebox.option["camLookaroundInverse"] = 0;
    opt_Game_Choicebox.option["enableMouse"] = 1;
    opt_Game_Choicebox.option["useGothic1Controls"] = 1;
    opt_Game_Slider.option["mouseSensitivity"] = 0.5;
    // ...
}

int Settings::getChoiceboxValue(std::string settingTopic, std::string settingOption) {
    if (settingTopic == "INTERNAL")
        return opt_Internal_Choicebox.getValue(settingOption);
    else if (settingTopic == "GAME")
        return opt_Game_Choicebox.getValue(settingOption);
    else if (settingTopic == "PERFORMANCE")
        return opt_Performance_Choicebox.getValue(settingOption);
    else if (settingTopic == "ENGINE")
        return opt_Engine_Choicebox.getValue(settingOption);
    else if (settingTopic == "VIDEO")
        return opt_Video_Choicebox.getValue(settingOption);
    else if (settingTopic == "SOUND")
        return opt_Sound_Choicebox.getValue(settingOption);
    else if (settingTopic == "KEYS")
        return -1; // TODO
    else if (settingTopic == "RENDERER_D3D")
        return opt_Renderer_D3D_Choicebox.getValue(settingOption);
    else 
        return -1;
}

void Settings::setChoiceboxValue(std::string settingTopic, std::string settingOption, int direction) {
    if (settingTopic == "INTERNAL")
        opt_Internal_Choicebox.option[settingOption] += direction;
    else if (settingTopic == "GAME")
        opt_Game_Choicebox.option[settingOption] += direction;
    else if (settingTopic == "PERFORMANCE")
        opt_Performance_Choicebox.option[settingOption] += direction;
    else if (settingTopic == "ENGINE")
        opt_Engine_Choicebox.option[settingOption] += direction;
    else if (settingTopic == "VIDEO")
        opt_Video_Choicebox.option[settingOption] += direction;
    else if (settingTopic == "SOUND")
        opt_Sound_Choicebox.option[settingOption] += direction;
    else if (settingTopic == "KEYS")
        return; // TODO
    else if (settingTopic == "RENDERER_D3D")
        opt_Renderer_D3D_Choicebox.option[settingOption] += direction;
}

void Settings::initStandardSettings () {
    /* Opt_Internal */
    opt_Internal_Choicebox.option.insert({"perfQualityIndex",0});   // custom settings = 0 or standard settings with 3 quality/perfomance steps
    opt_Internal_Choicebox.option.insert({"vidResIndex",0});
    opt_Internal_Choicebox.option.insert({"soundProviderIndex",0});
    opt_Internal_Choicebox.option.insert({"soundSpeakerIndex",0});
    opt_Internal_Choicebox.option.insert({"soundSampleRateIndex",0});
    opt_Internal_Slider.option.insert({"texDetailIndex",1.0});
    /* Opt_Game */
    opt_Game_Choicebox.option.insert({"subTitles",0});              // choose if you want to see windows with spoken words (1) or not (0), default is 0
    opt_Game_Choicebox.option.insert({"highlightMeleeFocus",2});    // here you can turn on an optional focus highlight effect during fighting
    opt_Game_Choicebox.option.insert({"highlightInteractFocus",0}); // here you can turn on an optional focus highlight during interactions
    opt_Game_Choicebox.option.insert({"camLookaroundInverse",0});   // inverts the camera-lookaround for UP and DOWN-direction (for both: mouse and keyboard)
    opt_Game_Choicebox.option.insert({"enableMouse",1});            // enable your mouse for gothic, default is 0
    opt_Game_Choicebox.option.insert({"useGothic1Controls",1});     // if you set this one to 0 you will have another fight interface (one key to attack). we feel the gothic 1 interface is more challenging, so we set the old controls to default with the new interface, the focus nsc stays locked until you move the mouse. in this mode the side attacks are being accessed with additional side attack keys.
    opt_Game_Choicebox.option.insert({"skyEffects",1});             // turn weather-effects (rain) on (1) or off (0), default is 1
    opt_Game_Choicebox.option.insert({"useSpeechReverbLevel",2});   // with this setting you can enable several reverb-settings for in-game-speech. 0: no reverb, 1: slight reverb, 2: full reverb (default: 2)
    opt_Game_Slider.option.insert({"mouseSensitivity",0.5});        // mouseSpeed in game between 0.0 and 1.0, default is 0.5
    /* Opt_Performance */
    opt_Performance_Choicebox.option.insert({"sightValue",6});      // range of visibility: 0=20% ... 14=300%, default is 4 (100%)
    opt_Performance_Slider.option.insert({"modelDetail",0.5});      // detail of models (LODing) from 0.0 to 1.0, default is 0.5
    /* Opt_Engine */
    opt_Engine_Choicebox.option.insert({"zVobFarClipZScale",3});    // with this setting you can tune the object visibility range. (range: 1..3) default: 1
    opt_Engine_Choicebox.option.insert({"zWaterAniEnabled",1});     // enables (1) or disables (0) water waves. disabling improves performance
    opt_Engine_Choicebox.option.insert({"zFarClipAlphaFade",1});    // enables (1) or disables (0) water distance fade and camera angle transparency dependencies. disabling improves performance
    opt_Engine_Choicebox.option.insert({"zWindEnabled",1});         // enables (1) or disables (0) in-game wind for objects/trees etc. improves performance (especially on slow cpu's) (default: 1)
    opt_Engine_Choicebox.option.insert({"zCloudShadowScale",0});    // this value enables (1) or disables (0) the cloudshadow effect during raining. range: (0.0-1.0) default: 0.0. attention: performance hog!
    opt_Engine_Choicebox.option.insert({"zAmbientPFXEnabled",1});   // enables (1) or disables (0) rendering of ambient particles. rendering ambient particles greatly limits your fillrate, so if you have a card with less fill-rate capabilities (e.g. geforce 2 MX versions) you may set this to "0" to improve performance. (default: 1)
    opt_Engine_Choicebox.option.insert({"zEnvMappingEnabled",1});   // enables (1) or disables (0) rendering of environmental effects (aka shiny/reflective surfaces). improves performance if deactivated (default: 1)
    /* Opt_Video */
    opt_Video_Choicebox.option.insert({"zVidDevice",0});            // index of graphic-device beginning with zero.
    opt_Video_Slider.option.insert({"zVidBrightness",0.5});         // brightness from 0.0 (dark) to 1.0 (bright)
    opt_Video_Slider.option.insert({"zVidContrast",0.5});           // contrast from 0.0 (low contrast) to 1.0 (high contrast)
    opt_Video_Slider.option.insert({"zVidGamma",0.5});              // gamma from 0.0 (dark) to 1.0 (bright)
    /* Opt_Sound */
    opt_Sound_Choicebox.option.insert({"musicEnabled",1});          // enables (1) or disables (0) music. Gothic needs less memory without music.
    opt_Sound_Choicebox.option.insert({"soundUseReverb",1});        // enables (1) or disables (0) in game reverb effects in indoor locations.
    opt_Sound_Slider.option.insert({"soundVolume",1.0});            // volume of sound and music, ranges between 0.0 (off) and 1.0 (noisy)
    opt_Sound_Slider.option.insert({"musicVolume",0.8});            // volume of sound and music, ranges between 0.0 (off) and 1.0 (noisy)
    /* Opt_Keys */
    // input: keyUp, ... 
    /* Opt_Renderer_D3D */
    opt_Renderer_D3D_Choicebox.option.insert({"zFogRadial",1});     // enables radial fog. this could be somehow slower on some grafic cards, but looks smoother. set to "0" if you have any problems with it; some cards without T&L don't support radial fog. On these cards, (although they are unsupported) it may be wise to deactivate radial fog.
}
