#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: upskillpower.sh,v 1.2 2023/06/22 05:31:07 wiz Exp $
#
# PROVIDE: upskillpower
# REQUIRE: mountcritremote
# BEFORE: upsdriver altqd downinterfaces 
# KEYWORD: shutdown

# This script shuts off power, if upsmon has decided to shutdown
# because of low battery/runtime.  This is logically part of upsmon
# but should run later in shutdown.

. /etc/rc.subr

name="upskillpower"
rcvar=upsmon

start_empty()
{
    # This is a shutdown-only file.
    true
}

killpower()
{
    if @PREFIX@/sbin/upsmon -K; then
	echo "upskillpower: POWER OFF commanded"
	@PREFIX@/sbin/upsdrvctl shutdown
    fi
}

start_cmd="start_empty"
stop_cmd="killpower"

load_rc_config $name
run_rc_command "$1"
