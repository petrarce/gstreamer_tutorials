#include <gst/gst.h>
#include <gst/rtsp-server/rtsp-server.h>

int main(int argc, char** argv)
{
	gst_init(&argc, &argv);

	//create rtsp server
	GstRTSPServer* rtspserver;
	rtspserver = gst_rtsp_server_new();

	//create glib main loop in default(NULL) context
	GMainLoop* loop = g_main_loop_new(NULL, FALSE);

	//attach server to default glib context
	gst_rtsp_server_attach(rtspserver, NULL);

	//start glib main loop
	g_main_loop_run(loop);
}
