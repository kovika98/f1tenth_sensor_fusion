/* Copyright 2021 Kovács Gergely Attila
*
*   Licensed under the Apache License,
*   Version 2.0(the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License. 
*   
*/

#include <f1tenth_sensor_fusion/cluster_tracker.h>
#include <pluginlib/class_list_macros.h>

namespace f1tenth_sensor_fusion
{

    class LidarTracker : public ClusterTracker
    {
    public:
        LidarTracker()
        {
            _config = TrackerConfig("laser_cloud", 20, 100, 0.1, "asd", "asd");
        }
        ~LidarTracker()
        {
            ROS_INFO("LidarTracker destructor");
        }
    };

    class CameraTracker : public ClusterTracker
    {
    public:
        CameraTracker()
        {
            _config = TrackerConfig("camera_cloud", 40, 400, 0.1, "camera", "points");
        }
        ~CameraTracker()
        {
            ROS_INFO("CameraTracker destructor");
        }
    };
}

PLUGINLIB_EXPORT_CLASS(f1tenth_sensor_fusion::LidarTracker, nodelet::Nodelet);
PLUGINLIB_EXPORT_CLASS(f1tenth_sensor_fusion::CameraTracker, nodelet::Nodelet);