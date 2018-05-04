#include <httpd.h>
#include <http_core.h>
#include <http_protocol.h>
#include <http_request.h>

/* Define prototypes */
static void register_hooks(apr_pool_t *pool);
static int hello_handler(request_rec *r);

module AP_MODULE_DECLARE_DATA hello_module=
{
	STANDARD20_MODULE_STUFF,
	NULL,	// Per-directory configuration handler
	NULL,	// Merge handler for per-directory configurations
	NULL,	// Per-server configuration handler
	NULL,	// Merge handler for per-server configurations
	NULL,	// Any directives we may have for httpd
	register_hooks	// Our hook registering function
};

static void register_hooks(apr_pool_t *pool)
{
	ap_hook_handler(hello_handler,NULL,NULL,APR_HOOK_LAST);
}

/* The handler function */
static int hello_handler(request_rec *r)
{
	/*
	* Check if this is a call for the "hello" handler.
	* If it is, we accept it and do stuff, otherwise return DECLINED.
	* and Apache will try other stuff
	*/
	if(!r->handler || strcmp(r->handler,"hello-handler")) return DECLINED;
	ap_rputs("Hello world!",r);
	return OK;
}

