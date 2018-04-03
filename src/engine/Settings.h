/* 
 * File:   Settings.h
 * Author: Migos (@AbsintheScripting)
 *
 * Created on 31. März 2018, 15:48
 */

#pragma once

#include <unordered_map>

class Settings {
public:
    Settings();
    ~Settings();
    
    /**
     * Init all global user definable settings
     */
    void initStandardSettings ();
    
    /**
     * set user settings to standard settings
     */
    void setSettingsToStandard();
    
    /**
     * get a user setting value for a choicebox
     * @param settingTopic
     * @param settingOption
     * @return 
     */
    int getChoiceboxValue(std::string settingTopic, std::string settingOption);
    
    void setChoiceboxValue(std::string settingTopic, std::string settingOption, int direction);
private:
    /**
     * simple map for storing all values
     */
    template <typename T>
    struct globalSetting {
        std::unordered_map<std::string, T> option;
        T getValue (std::string key) {
            T out;
            try {
                out = option.at(key);
            } catch (const std::out_of_range& oor) {
                // TODO: Maybe better error handling than uninit var return
            }
            return out;
        }
    };
    
    /* Opt_Internal */
    globalSetting<int> opt_Internal_Choicebox;
    globalSetting<float> opt_Internal_Slider;
    /* Opt_Game */
    globalSetting<int> opt_Game_Choicebox;
    globalSetting<float> opt_Game_Slider;
    /* Opt_Performance */
    globalSetting<int> opt_Performance_Choicebox;
    globalSetting<float> opt_Performance_Slider;
    /* Opt_Engine */
    globalSetting<int> opt_Engine_Choicebox;
    /* Opt_Video */
    globalSetting<int> opt_Video_Choicebox;
    globalSetting<float> opt_Video_Slider;
    /* Opt_Sound */
    globalSetting<int> opt_Sound_Choicebox;
    globalSetting<float> opt_Sound_Slider;
    /* Opt_Keys */
    // TODO
    /* Opt_Renderer_D3D */
    globalSetting<int> opt_Renderer_D3D_Choicebox;
};