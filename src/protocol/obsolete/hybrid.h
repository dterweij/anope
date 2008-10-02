/* Hybrid IRCD functions
 *
 * (C) 2003-2008 Anope Team
 * Contact us at info@anope.org
 *
 * Please read COPYING and README for furhter details.
 *
 * Based on the original code of Epona by Lara.
 * Based on the original code of Services by Andy Church.
 *
 *
 */

#define UMODE_a 0x00000001  /* Admin status */
#define UMODE_b 0x00000080  /* See bot and drone flooding notices */
#define UMODE_c 0x00000100  /* Client connection/quit notices */
#define UMODE_d 0x00000200  /* See debugging notices */
#define UMODE_f 0x00000400  /* See I: line full notices */
#define UMODE_g 0x00000800  /* Server Side Ignore */
#define UMODE_i 0x00000004  /* Not shown in NAMES or WHO unless you share a channel */
#define UMODE_k 0x00001000  /* See server generated KILL messages */
#define UMODE_l 0x00002000  /* See LOCOPS messages */
#define UMODE_n 0x00004000  /* See client nick changes */
#define UMODE_o 0x00000008  /* Operator status */
#define UMODE_r 0x00000010  /* See rejected client notices */
#define UMODE_s 0x00008000  /* See general server notices */
#define UMODE_u 0x00010000  /* See unauthorized client notices */
#define UMODE_w 0x00000020  /* See server generated WALLOPS */
#define UMODE_x 0x00020000  /* See remote server connection and split notices */
#define UMODE_y 0x00040000  /* See LINKS, STATS (if configured), TRACE notices */
#define UMODE_z 0x00080000  /* See oper generated WALLOPS */

#define CMODE_i 0x00000001     /* Invite only */
#define CMODE_m 0x00000002     /* Users without +v/h/o cannot send text to the channel */
#define CMODE_n 0x00000004     /* Users must be in the channel to send text to it */
#define CMODE_p 0x00000008     /* Private is obsolete, this now restricts KNOCK */
#define CMODE_s 0x00000010     /* The channel does not show up on NAMES or LIST */
#define CMODE_t 0x00000020     /* Only chanops can change the topic */
#define CMODE_k 0x00000040     /* Key/password for the channel. */
#define CMODE_l 0x00000080     /* Limit the number of users in a channel */
#define CMODE_a 0x00000400     /* Anonymous ops, chanops are hidden */


#define DEFAULT_MLOCK CMODE_n | CMODE_t

void hybrid_set_umode(User * user, int ac, const char **av);
void hybrid_cmd_topic(const char *whosets, const char *chan, const char *whosetit, const char *topic, time_t when);
void hybrid_SendVhostDel(User * u);
void hybrid_SendAkill(const char *user, const char *host, const char *who, time_t when,time_t expires, const char *reason);
void hybrid_SendSVSKill(const char *source, const char *user, const char *buf);
void hybrid_SendSVSMode(User * u, int ac, const char **av);
void hybrid_cmd_372(const char *source, const char *msg);
void hybrid_cmd_372_error(const char *source);
void hybrid_cmd_375(const char *source);
void hybrid_cmd_376(const char *source);
void hybrid_cmd_nick(const char *nick, const char *name, const char *modes);
void hybrid_cmd_guest_nick(const char *nick, const char *user, const char *host, const char *real, const char *modes);
void hybrid_cmd_mode(const char *source, const char *dest, const char *buf);
void hybrid_cmd_bot_nick(const char *nick, const char *user, const char *host, const char *real, const char *modes);
void hybrid_cmd_kick(const char *source, const char *chan, const char *user, const char *buf);
void hybrid_cmd_notice_ops(const char *source, const char *dest, const char *buf);
void hybrid_cmd_notice(const char *source, const char *dest, const char *buf);
void hybrid_cmd_notice2(const char *source, const char *dest, const char *msg);
void hybrid_cmd_privmsg(const char *source, const char *dest, const char *buf);
void hybrid_cmd_privmsg2(const char *source, const char *dest, const char *msg);
void hybrid_cmd_serv_notice(const char *source, const char *dest, const char *msg);
void hybrid_cmd_serv_privmsg(const char *source, const char *dest, const char *msg);
void hybrid_cmd_bot_chan_mode(const char *nick, const char *chan);
void hybrid_cmd_351(const char *source);
void hybrid_cmd_quit(const char *source, const char *buf);
void hybrid_cmd_pong(const char *servname, const char *who);
void hybrid_cmd_join(const char *user, const char *channel, time_t chantime);
void hybrid_cmd_unsqline(const char *user);
void hybrid_cmd_invite(const char *source, const char *chan, const char *nick);
void hybrid_cmd_part(const char *nick, const char *chan, const char *buf);
void hybrid_cmd_391(const char *source, const char *timestr);
void hybrid_cmd_250(const char *buf);
void hybrid_cmd_307(const char *buf);
void hybrid_cmd_311(const char *buf);
void hybrid_cmd_312(const char *buf);
void hybrid_cmd_317(const char *buf);
void hybrid_cmd_219(const char *source, const char *letter);
void hybrid_cmd_401(const char *source, const char *who);
void hybrid_cmd_318(const char *source, const char *who);
void hybrid_cmd_242(const char *buf);
void hybrid_cmd_243(const char *buf);
void hybrid_cmd_211(const char *buf);
void hybrid_cmd_global(const char *source, const char *buf);
void hybrid_cmd_global_legacy(const char *source, const char *fmt);
void hybrid_cmd_sqline(const char *mask, const char *reason);
void hybrid_cmd_squit(const char *servname, const char *message);
void hybrid_cmd_svso(const char *source, const char *nick, const char *flag);
void hybrid_cmd_chg_nick(const char *oldnick, const char *newnick);
void hybrid_cmd_svsnick(const char *source, const char *guest, time_t when);
void hybrid_cmd_vhost_on(const char *nick, const char *vIdent, const char *vhost);
void hybrid_cmd_connect(int servernum);
void hybrid_cmd_svshold(const char *nick);
void hybrid_cmd_release_svshold(const char *nick);
void hybrid_cmd_unsgline(const char *mask);
void hybrid_cmd_unszline(const char *mask);
void hybrid_cmd_szline(const char *mask, const char *reason, const char *whom);
void hybrid_cmd_sgline(const char *mask, const char *reason);
void hybrid_cmd_unban(const char *name, const char *nick);
void hybrid_SendSVSMode_chan(const char *name, const char *mode, const char *nick);
void hybrid_cmd_svid_umode(const char *nick, time_t ts);
void hybrid_cmd_nc_change(User * u);
void hybrid_cmd_svid_umode2(User * u, const char *ts);
void hybrid_cmd_svid_umode3(User * u, const char *ts);
void hybrid_cmd_eob();
int hybrid_flood_mode_check(const char *value);
void hybrid_cmd_jupe(const char *jserver, const char *who, const char *reason);
int hybrid_valid_nick(const char *nick);
void hybrid_cmd_ctcp(const char *source, const char *dest, const char *buf);

class HybridIRCdProto : public IRCDProtoNew {
	public:
		void SendAkillDel(const char *, const char *);
} ircd_proto;
