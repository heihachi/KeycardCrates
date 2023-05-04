class KeyCardLocations
{
    float x, y, z;
    float building_x, building_y, building_z;

    int door_index;

    string Location_Name;
    string BuildingClassName;
    string keycard_class_name;
    string keycard_item_name;
    string alarm_sound;

    bool use_light;
    bool use_alarm;
    bool use_amount;

    int relock_time;

    int ActionID = -1;
    bool use_actions = false;

    void KeyCardLocations(float x_, float y_, float z_, float building_x_, float building_y_, float building_z_, int door_index_, string Location_Name_,  string BuildingClassname_ , string keycard_class_name_, bool single_use_, bool use_light_,  float light_height_, string alarm_sound_, bool use_alarm_, int relock_time_) 
    {
        x = x_;
        y = y_;
        z = z_;

        building_x = building_x_;
        building_y = building_y_;
        building_z = building_z_;

        door_index = door_index_;
        Location_Name = Location_Name_; 
        BuildingClassName = BuildingClassname_;
        keycard_class_name = keycard_class_name_;


        use_amount = single_use_;
        use_light  = use_light_;

        // light_height = light_height_;

        alarm_sound = alarm_sound_;

        use_alarm = use_alarm_;

        relock_time = relock_time_;
    }
};

class KeyCardLockedLocations
{
    vector door_pos;
    bool use_light;
    float light_height;

    void KeyCardLockedLocations(vector door_pos_, bool use_light_/*, float light_height_*/)
    {
        door_pos = door_pos_;
        use_light = use_light_;
        // light_height = light_height_;
    }
};