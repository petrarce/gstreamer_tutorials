#include <gst/gst.h>
#include <gst/rtsp-server/rtsp-server.h>
#include <string>
#include <iostream>
int main(int argc, char** argv)
{

	//port, which should be listened for rtp video stream
	std::string port = (argc == 2)? std::string(argv[1]) : "4000";
	gst_init(NULL, NULL);

	//create rtsp server. By default it will listen connections on port 8554
	GstRTSPServer* rtspserver;
	rtspserver = gst_rtsp_server_new();

	//create glib main loop in default(NULL) context
	GMainLoop* loop = g_main_loop_new(NULL, FALSE);

	//attach server to default glib context
	gst_rtsp_server_attach(rtspserver, NULL);

	//create a pipline for receiving rtsp content
	GstRTSPMediaFactory* factory;
	factory = gst_rtsp_media_factory_new();
	//...rtpjpegdepay ! rtpjpegpay... part is required for rtsp to be able to acces to payload-type(pt) property
	std::string gstLaunchString = "( udpsrc port=" + port + "  caps=\"application/x-rtp\" ! rtpjpegdepay ! rtpjpegpay name=pay0 )";
	gst_rtsp_media_factory_set_launch(factory, gstLaunchString.c_str());
	gst_rtsp_media_factory_set_shared(factory, true);

	//setup mounts
	GstRTSPMountPoints* mounts;
	mounts = gst_rtsp_server_get_mount_points(rtspserver);
	gst_rtsp_mount_points_add_factory(mounts, "/test", factory);
	g_object_unref(mounts);

	//start glib main loop
	std::cout << "Starting RTSP server\n";
	g_main_loop_run(loop);

	g_object_unref(loop);
	gst_object_unref(rtspserver);
	gst_object_unref(factory);
	std::cout << "RTSP server is terminated\n";
}
