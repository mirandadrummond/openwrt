/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         pcap_parse
#define yylex           pcap_lex
#define yyerror         pcap_error
#define yydebug         pcap_debug
#define yynerrs         pcap_nerrs

/* First part of user prologue.  */
#line 47 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"

/*
 * Copyright (c) 1988, 1989, 1990, 1991, 1992, 1993, 1994, 1995, 1996
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that: (1) source code distributions
 * retain the above copyright notice and this paragraph in its entirety, (2)
 * distributions including binary code include the above copyright notice and
 * this paragraph in its entirety in the documentation or other materials
 * provided with the distribution, and (3) all advertising materials mentioning
 * features or use of this software display the following acknowledgement:
 * ``This product includes software developed by the University of California,
 * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of
 * the University nor the names of its contributors may be used to endorse
 * or promote products derived from this software without specific prior
 * written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

/*
 * grammar.h requires gencode.h and sometimes breaks in a polluted namespace
 * (see ftmacros.h), so include it early.
 */
#include "gencode.h"
#include "grammar.h"

#include <stdlib.h>

#ifndef _WIN32
#include <sys/types.h>
#include <sys/socket.h>

#if __STDC__
struct mbuf;
struct rtentry;
#endif

#include <netinet/in.h>
#include <arpa/inet.h>
#endif /* _WIN32 */

#include <stdio.h>

#include "diag-control.h"

#include "pcap-int.h"

#include "scanner.h"

#include "llc.h"
#include "ieee80211.h"
#include "pflog.h"
#include <pcap/namedb.h>

#ifdef HAVE_OS_PROTO_H
#include "os-proto.h"
#endif

#ifdef YYBYACC
/*
 * Both Berkeley YACC and Bison define yydebug (under whatever name
 * it has) as a global, but Bison does so only if YYDEBUG is defined.
 * Berkeley YACC define it even if YYDEBUG isn't defined; declare it
 * here to suppress a warning.
 */
#if !defined(YYDEBUG)
extern int yydebug;
#endif

/*
 * In Berkeley YACC, yynerrs (under whatever name it has) is global,
 * even if it's building a reentrant parser.  In Bison, it's local
 * in reentrant parsers.
 *
 * Declare it to squelch a warning.
 */
extern int yynerrs;
#endif

#define QSET(q, p, d, a) (q).proto = (unsigned char)(p),\
			 (q).dir = (unsigned char)(d),\
			 (q).addr = (unsigned char)(a)

struct tok {
	int v;			/* value */
	const char *s;		/* string */
};

static const struct tok ieee80211_types[] = {
	{ IEEE80211_FC0_TYPE_DATA, "data" },
	{ IEEE80211_FC0_TYPE_MGT, "mgt" },
	{ IEEE80211_FC0_TYPE_MGT, "management" },
	{ IEEE80211_FC0_TYPE_CTL, "ctl" },
	{ IEEE80211_FC0_TYPE_CTL, "control" },
	{ 0, NULL }
};
static const struct tok ieee80211_mgt_subtypes[] = {
	{ IEEE80211_FC0_SUBTYPE_ASSOC_REQ, "assocreq" },
	{ IEEE80211_FC0_SUBTYPE_ASSOC_REQ, "assoc-req" },
	{ IEEE80211_FC0_SUBTYPE_ASSOC_RESP, "assocresp" },
	{ IEEE80211_FC0_SUBTYPE_ASSOC_RESP, "assoc-resp" },
	{ IEEE80211_FC0_SUBTYPE_REASSOC_REQ, "reassocreq" },
	{ IEEE80211_FC0_SUBTYPE_REASSOC_REQ, "reassoc-req" },
	{ IEEE80211_FC0_SUBTYPE_REASSOC_RESP, "reassocresp" },
	{ IEEE80211_FC0_SUBTYPE_REASSOC_RESP, "reassoc-resp" },
	{ IEEE80211_FC0_SUBTYPE_PROBE_REQ, "probereq" },
	{ IEEE80211_FC0_SUBTYPE_PROBE_REQ, "probe-req" },
	{ IEEE80211_FC0_SUBTYPE_PROBE_RESP, "proberesp" },
	{ IEEE80211_FC0_SUBTYPE_PROBE_RESP, "probe-resp" },
	{ IEEE80211_FC0_SUBTYPE_BEACON, "beacon" },
	{ IEEE80211_FC0_SUBTYPE_ATIM, "atim" },
	{ IEEE80211_FC0_SUBTYPE_DISASSOC, "disassoc" },
	{ IEEE80211_FC0_SUBTYPE_DISASSOC, "disassociation" },
	{ IEEE80211_FC0_SUBTYPE_AUTH, "auth" },
	{ IEEE80211_FC0_SUBTYPE_AUTH, "authentication" },
	{ IEEE80211_FC0_SUBTYPE_DEAUTH, "deauth" },
	{ IEEE80211_FC0_SUBTYPE_DEAUTH, "deauthentication" },
	{ 0, NULL }
};
static const struct tok ieee80211_ctl_subtypes[] = {
	{ IEEE80211_FC0_SUBTYPE_PS_POLL, "ps-poll" },
	{ IEEE80211_FC0_SUBTYPE_RTS, "rts" },
	{ IEEE80211_FC0_SUBTYPE_CTS, "cts" },
	{ IEEE80211_FC0_SUBTYPE_ACK, "ack" },
	{ IEEE80211_FC0_SUBTYPE_CF_END, "cf-end" },
	{ IEEE80211_FC0_SUBTYPE_CF_END_ACK, "cf-end-ack" },
	{ 0, NULL }
};
static const struct tok ieee80211_data_subtypes[] = {
	{ IEEE80211_FC0_SUBTYPE_DATA, "data" },
	{ IEEE80211_FC0_SUBTYPE_CF_ACK, "data-cf-ack" },
	{ IEEE80211_FC0_SUBTYPE_CF_POLL, "data-cf-poll" },
	{ IEEE80211_FC0_SUBTYPE_CF_ACPL, "data-cf-ack-poll" },
	{ IEEE80211_FC0_SUBTYPE_NODATA, "null" },
	{ IEEE80211_FC0_SUBTYPE_NODATA_CF_ACK, "cf-ack" },
	{ IEEE80211_FC0_SUBTYPE_NODATA_CF_POLL, "cf-poll"  },
	{ IEEE80211_FC0_SUBTYPE_NODATA_CF_ACPL, "cf-ack-poll" },
	{ IEEE80211_FC0_SUBTYPE_QOS|IEEE80211_FC0_SUBTYPE_DATA, "qos-data" },
	{ IEEE80211_FC0_SUBTYPE_QOS|IEEE80211_FC0_SUBTYPE_CF_ACK, "qos-data-cf-ack" },
	{ IEEE80211_FC0_SUBTYPE_QOS|IEEE80211_FC0_SUBTYPE_CF_POLL, "qos-data-cf-poll" },
	{ IEEE80211_FC0_SUBTYPE_QOS|IEEE80211_FC0_SUBTYPE_CF_ACPL, "qos-data-cf-ack-poll" },
	{ IEEE80211_FC0_SUBTYPE_QOS|IEEE80211_FC0_SUBTYPE_NODATA, "qos" },
	{ IEEE80211_FC0_SUBTYPE_QOS|IEEE80211_FC0_SUBTYPE_NODATA_CF_POLL, "qos-cf-poll" },
	{ IEEE80211_FC0_SUBTYPE_QOS|IEEE80211_FC0_SUBTYPE_NODATA_CF_ACPL, "qos-cf-ack-poll" },
	{ 0, NULL }
};
static const struct tok llc_s_subtypes[] = {
	{ LLC_RR, "rr" },
	{ LLC_RNR, "rnr" },
	{ LLC_REJ, "rej" },
	{ 0, NULL }
};
static const struct tok llc_u_subtypes[] = {
	{ LLC_UI, "ui" },
	{ LLC_UA, "ua" },
	{ LLC_DISC, "disc" },
	{ LLC_DM, "dm" },
	{ LLC_SABME, "sabme" },
	{ LLC_TEST, "test" },
	{ LLC_XID, "xid" },
	{ LLC_FRMR, "frmr" },
	{ 0, NULL }
};
struct type2tok {
	int type;
	const struct tok *tok;
};
static const struct type2tok ieee80211_type_subtypes[] = {
	{ IEEE80211_FC0_TYPE_MGT, ieee80211_mgt_subtypes },
	{ IEEE80211_FC0_TYPE_CTL, ieee80211_ctl_subtypes },
	{ IEEE80211_FC0_TYPE_DATA, ieee80211_data_subtypes },
	{ 0, NULL }
};

static int
str2tok(const char *str, const struct tok *toks)
{
	int i;

	for (i = 0; toks[i].s != NULL; i++) {
		if (pcap_strcasecmp(toks[i].s, str) == 0) {
			/*
			 * Just in case somebody is using this to
			 * generate values of -1/0xFFFFFFFF.
			 * That won't work, as it's indistinguishable
			 * from an error.
			 */
			if (toks[i].v == -1)
				abort();
			return (toks[i].v);
		}
	}
	return (-1);
}

static const struct qual qerr = { Q_UNDEF, Q_UNDEF, Q_UNDEF, Q_UNDEF };

static void
yyerror(void *yyscanner _U_, compiler_state_t *cstate, const char *msg)
{
	bpf_set_error(cstate, "can't parse filter expression: %s", msg);
}

static const struct tok pflog_reasons[] = {
	{ PFRES_MATCH,		"match" },
	{ PFRES_BADOFF,		"bad-offset" },
	{ PFRES_FRAG,		"fragment" },
	{ PFRES_SHORT,		"short" },
	{ PFRES_NORM,		"normalize" },
	{ PFRES_MEMORY,		"memory" },
	{ PFRES_TS,		"bad-timestamp" },
	{ PFRES_CONGEST,	"congestion" },
	{ PFRES_IPOPTIONS,	"ip-option" },
	{ PFRES_PROTCKSUM,	"proto-cksum" },
	{ PFRES_BADSTATE,	"state-mismatch" },
	{ PFRES_STATEINS,	"state-insert" },
	{ PFRES_MAXSTATES,	"state-limit" },
	{ PFRES_SRCLIMIT,	"src-limit" },
	{ PFRES_SYNPROXY,	"synproxy" },
#if defined(__FreeBSD__)
	{ PFRES_MAPFAILED,	"map-failed" },
#elif defined(__NetBSD__)
	{ PFRES_STATELOCKED,	"state-locked" },
#elif defined(__OpenBSD__)
	{ PFRES_TRANSLATE,	"translate" },
	{ PFRES_NOROUTE,	"no-route" },
#elif defined(__APPLE__)
	{ PFRES_DUMMYNET,	"dummynet" },
#endif
	{ 0, NULL }
};

static int
pfreason_to_num(compiler_state_t *cstate, const char *reason)
{
	int i;

	i = str2tok(reason, pflog_reasons);
	if (i == -1)
		bpf_set_error(cstate, "unknown PF reason \"%s\"", reason);
	return (i);
}

static const struct tok pflog_actions[] = {
	{ PF_PASS,		"pass" },
	{ PF_PASS,		"accept" },	/* alias for "pass" */
	{ PF_DROP,		"drop" },
	{ PF_DROP,		"block" },	/* alias for "drop" */
	{ PF_SCRUB,		"scrub" },
	{ PF_NOSCRUB,		"noscrub" },
	{ PF_NAT,		"nat" },
	{ PF_NONAT,		"nonat" },
	{ PF_BINAT,		"binat" },
	{ PF_NOBINAT,		"nobinat" },
	{ PF_RDR,		"rdr" },
	{ PF_NORDR,		"nordr" },
	{ PF_SYNPROXY_DROP,	"synproxy-drop" },
#if defined(__FreeBSD__)
	{ PF_DEFER,		"defer" },
#elif defined(__OpenBSD__)
	{ PF_DEFER,		"defer" },
	{ PF_MATCH,		"match" },
	{ PF_DIVERT,		"divert" },
	{ PF_RT,		"rt" },
	{ PF_AFRT,		"afrt" },
#elif defined(__APPLE__)
	{ PF_DUMMYNET,		"dummynet" },
	{ PF_NODUMMYNET,	"nodummynet" },
	{ PF_NAT64,		"nat64" },
	{ PF_NONAT64,		"nonat64" },
#endif
	{ 0, NULL },
};

static int
pfaction_to_num(compiler_state_t *cstate, const char *action)
{
	int i;

	i = str2tok(action, pflog_actions);
	if (i == -1)
		bpf_set_error(cstate, "unknown PF action \"%s\"", action);
	return (i);
}

/*
 * For calls that might return an "an error occurred" value.
 */
#define CHECK_INT_VAL(val)	if (val == -1) YYABORT
#define CHECK_PTR_VAL(val)	if (val == NULL) YYABORT

DIAG_OFF_BISON_BYACC

#line 378 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "grammar.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_DST = 3,                        /* DST  */
  YYSYMBOL_SRC = 4,                        /* SRC  */
  YYSYMBOL_HOST = 5,                       /* HOST  */
  YYSYMBOL_GATEWAY = 6,                    /* GATEWAY  */
  YYSYMBOL_NET = 7,                        /* NET  */
  YYSYMBOL_NETMASK = 8,                    /* NETMASK  */
  YYSYMBOL_PORT = 9,                       /* PORT  */
  YYSYMBOL_PORTRANGE = 10,                 /* PORTRANGE  */
  YYSYMBOL_LESS = 11,                      /* LESS  */
  YYSYMBOL_GREATER = 12,                   /* GREATER  */
  YYSYMBOL_PROTO = 13,                     /* PROTO  */
  YYSYMBOL_PROTOCHAIN = 14,                /* PROTOCHAIN  */
  YYSYMBOL_CBYTE = 15,                     /* CBYTE  */
  YYSYMBOL_ARP = 16,                       /* ARP  */
  YYSYMBOL_RARP = 17,                      /* RARP  */
  YYSYMBOL_IP = 18,                        /* IP  */
  YYSYMBOL_SCTP = 19,                      /* SCTP  */
  YYSYMBOL_TCP = 20,                       /* TCP  */
  YYSYMBOL_UDP = 21,                       /* UDP  */
  YYSYMBOL_ICMP = 22,                      /* ICMP  */
  YYSYMBOL_IGMP = 23,                      /* IGMP  */
  YYSYMBOL_IGRP = 24,                      /* IGRP  */
  YYSYMBOL_PIM = 25,                       /* PIM  */
  YYSYMBOL_VRRP = 26,                      /* VRRP  */
  YYSYMBOL_CARP = 27,                      /* CARP  */
  YYSYMBOL_ATALK = 28,                     /* ATALK  */
  YYSYMBOL_AARP = 29,                      /* AARP  */
  YYSYMBOL_DECNET = 30,                    /* DECNET  */
  YYSYMBOL_LAT = 31,                       /* LAT  */
  YYSYMBOL_SCA = 32,                       /* SCA  */
  YYSYMBOL_MOPRC = 33,                     /* MOPRC  */
  YYSYMBOL_MOPDL = 34,                     /* MOPDL  */
  YYSYMBOL_TK_BROADCAST = 35,              /* TK_BROADCAST  */
  YYSYMBOL_TK_MULTICAST = 36,              /* TK_MULTICAST  */
  YYSYMBOL_NUM = 37,                       /* NUM  */
  YYSYMBOL_INBOUND = 38,                   /* INBOUND  */
  YYSYMBOL_OUTBOUND = 39,                  /* OUTBOUND  */
  YYSYMBOL_IFINDEX = 40,                   /* IFINDEX  */
  YYSYMBOL_PF_IFNAME = 41,                 /* PF_IFNAME  */
  YYSYMBOL_PF_RSET = 42,                   /* PF_RSET  */
  YYSYMBOL_PF_RNR = 43,                    /* PF_RNR  */
  YYSYMBOL_PF_SRNR = 44,                   /* PF_SRNR  */
  YYSYMBOL_PF_REASON = 45,                 /* PF_REASON  */
  YYSYMBOL_PF_ACTION = 46,                 /* PF_ACTION  */
  YYSYMBOL_TYPE = 47,                      /* TYPE  */
  YYSYMBOL_SUBTYPE = 48,                   /* SUBTYPE  */
  YYSYMBOL_DIR = 49,                       /* DIR  */
  YYSYMBOL_ADDR1 = 50,                     /* ADDR1  */
  YYSYMBOL_ADDR2 = 51,                     /* ADDR2  */
  YYSYMBOL_ADDR3 = 52,                     /* ADDR3  */
  YYSYMBOL_ADDR4 = 53,                     /* ADDR4  */
  YYSYMBOL_RA = 54,                        /* RA  */
  YYSYMBOL_TA = 55,                        /* TA  */
  YYSYMBOL_LINK = 56,                      /* LINK  */
  YYSYMBOL_GEQ = 57,                       /* GEQ  */
  YYSYMBOL_LEQ = 58,                       /* LEQ  */
  YYSYMBOL_NEQ = 59,                       /* NEQ  */
  YYSYMBOL_ID = 60,                        /* ID  */
  YYSYMBOL_EID = 61,                       /* EID  */
  YYSYMBOL_HID = 62,                       /* HID  */
  YYSYMBOL_HID6 = 63,                      /* HID6  */
  YYSYMBOL_AID = 64,                       /* AID  */
  YYSYMBOL_LSH = 65,                       /* LSH  */
  YYSYMBOL_RSH = 66,                       /* RSH  */
  YYSYMBOL_LEN = 67,                       /* LEN  */
  YYSYMBOL_IPV6 = 68,                      /* IPV6  */
  YYSYMBOL_ICMPV6 = 69,                    /* ICMPV6  */
  YYSYMBOL_AH = 70,                        /* AH  */
  YYSYMBOL_ESP = 71,                       /* ESP  */
  YYSYMBOL_VLAN = 72,                      /* VLAN  */
  YYSYMBOL_MPLS = 73,                      /* MPLS  */
  YYSYMBOL_PPPOED = 74,                    /* PPPOED  */
  YYSYMBOL_PPPOES = 75,                    /* PPPOES  */
  YYSYMBOL_GENEVE = 76,                    /* GENEVE  */
  YYSYMBOL_BATADV = 77,                    /* BATADV  */
  YYSYMBOL_ISO = 78,                       /* ISO  */
  YYSYMBOL_ESIS = 79,                      /* ESIS  */
  YYSYMBOL_CLNP = 80,                      /* CLNP  */
  YYSYMBOL_ISIS = 81,                      /* ISIS  */
  YYSYMBOL_L1 = 82,                        /* L1  */
  YYSYMBOL_L2 = 83,                        /* L2  */
  YYSYMBOL_IIH = 84,                       /* IIH  */
  YYSYMBOL_LSP = 85,                       /* LSP  */
  YYSYMBOL_SNP = 86,                       /* SNP  */
  YYSYMBOL_CSNP = 87,                      /* CSNP  */
  YYSYMBOL_PSNP = 88,                      /* PSNP  */
  YYSYMBOL_STP = 89,                       /* STP  */
  YYSYMBOL_IPX = 90,                       /* IPX  */
  YYSYMBOL_NETBEUI = 91,                   /* NETBEUI  */
  YYSYMBOL_LANE = 92,                      /* LANE  */
  YYSYMBOL_LLC = 93,                       /* LLC  */
  YYSYMBOL_METAC = 94,                     /* METAC  */
  YYSYMBOL_BCC = 95,                       /* BCC  */
  YYSYMBOL_SC = 96,                        /* SC  */
  YYSYMBOL_ILMIC = 97,                     /* ILMIC  */
  YYSYMBOL_OAMF4EC = 98,                   /* OAMF4EC  */
  YYSYMBOL_OAMF4SC = 99,                   /* OAMF4SC  */
  YYSYMBOL_OAM = 100,                      /* OAM  */
  YYSYMBOL_OAMF4 = 101,                    /* OAMF4  */
  YYSYMBOL_CONNECTMSG = 102,               /* CONNECTMSG  */
  YYSYMBOL_METACONNECT = 103,              /* METACONNECT  */
  YYSYMBOL_VPI = 104,                      /* VPI  */
  YYSYMBOL_VCI = 105,                      /* VCI  */
  YYSYMBOL_RADIO = 106,                    /* RADIO  */
  YYSYMBOL_FISU = 107,                     /* FISU  */
  YYSYMBOL_LSSU = 108,                     /* LSSU  */
  YYSYMBOL_MSU = 109,                      /* MSU  */
  YYSYMBOL_HFISU = 110,                    /* HFISU  */
  YYSYMBOL_HLSSU = 111,                    /* HLSSU  */
  YYSYMBOL_HMSU = 112,                     /* HMSU  */
  YYSYMBOL_SIO = 113,                      /* SIO  */
  YYSYMBOL_OPC = 114,                      /* OPC  */
  YYSYMBOL_DPC = 115,                      /* DPC  */
  YYSYMBOL_SLS = 116,                      /* SLS  */
  YYSYMBOL_HSIO = 117,                     /* HSIO  */
  YYSYMBOL_HOPC = 118,                     /* HOPC  */
  YYSYMBOL_HDPC = 119,                     /* HDPC  */
  YYSYMBOL_HSLS = 120,                     /* HSLS  */
  YYSYMBOL_LEX_ERROR = 121,                /* LEX_ERROR  */
  YYSYMBOL_OR = 122,                       /* OR  */
  YYSYMBOL_AND = 123,                      /* AND  */
  YYSYMBOL_124_ = 124,                     /* '!'  */
  YYSYMBOL_125_ = 125,                     /* '|'  */
  YYSYMBOL_126_ = 126,                     /* '&'  */
  YYSYMBOL_127_ = 127,                     /* '+'  */
  YYSYMBOL_128_ = 128,                     /* '-'  */
  YYSYMBOL_129_ = 129,                     /* '*'  */
  YYSYMBOL_130_ = 130,                     /* '/'  */
  YYSYMBOL_UMINUS = 131,                   /* UMINUS  */
  YYSYMBOL_132_ = 132,                     /* ')'  */
  YYSYMBOL_133_ = 133,                     /* '('  */
  YYSYMBOL_134_ = 134,                     /* '>'  */
  YYSYMBOL_135_ = 135,                     /* '='  */
  YYSYMBOL_136_ = 136,                     /* '<'  */
  YYSYMBOL_137_ = 137,                     /* '['  */
  YYSYMBOL_138_ = 138,                     /* ']'  */
  YYSYMBOL_139_ = 139,                     /* ':'  */
  YYSYMBOL_140_ = 140,                     /* '%'  */
  YYSYMBOL_141_ = 141,                     /* '^'  */
  YYSYMBOL_YYACCEPT = 142,                 /* $accept  */
  YYSYMBOL_prog = 143,                     /* prog  */
  YYSYMBOL_null = 144,                     /* null  */
  YYSYMBOL_expr = 145,                     /* expr  */
  YYSYMBOL_and = 146,                      /* and  */
  YYSYMBOL_or = 147,                       /* or  */
  YYSYMBOL_id = 148,                       /* id  */
  YYSYMBOL_nid = 149,                      /* nid  */
  YYSYMBOL_not = 150,                      /* not  */
  YYSYMBOL_paren = 151,                    /* paren  */
  YYSYMBOL_pid = 152,                      /* pid  */
  YYSYMBOL_qid = 153,                      /* qid  */
  YYSYMBOL_term = 154,                     /* term  */
  YYSYMBOL_head = 155,                     /* head  */
  YYSYMBOL_rterm = 156,                    /* rterm  */
  YYSYMBOL_pqual = 157,                    /* pqual  */
  YYSYMBOL_dqual = 158,                    /* dqual  */
  YYSYMBOL_aqual = 159,                    /* aqual  */
  YYSYMBOL_ndaqual = 160,                  /* ndaqual  */
  YYSYMBOL_pname = 161,                    /* pname  */
  YYSYMBOL_other = 162,                    /* other  */
  YYSYMBOL_pbatadv = 163,                  /* pbatadv  */
  YYSYMBOL_pfvar = 164,                    /* pfvar  */
  YYSYMBOL_p80211 = 165,                   /* p80211  */
  YYSYMBOL_type = 166,                     /* type  */
  YYSYMBOL_subtype = 167,                  /* subtype  */
  YYSYMBOL_type_subtype = 168,             /* type_subtype  */
  YYSYMBOL_pllc = 169,                     /* pllc  */
  YYSYMBOL_dir = 170,                      /* dir  */
  YYSYMBOL_reason = 171,                   /* reason  */
  YYSYMBOL_action = 172,                   /* action  */
  YYSYMBOL_relop = 173,                    /* relop  */
  YYSYMBOL_irelop = 174,                   /* irelop  */
  YYSYMBOL_arth = 175,                     /* arth  */
  YYSYMBOL_narth = 176,                    /* narth  */
  YYSYMBOL_byteop = 177,                   /* byteop  */
  YYSYMBOL_pnum = 178,                     /* pnum  */
  YYSYMBOL_atmtype = 179,                  /* atmtype  */
  YYSYMBOL_atmmultitype = 180,             /* atmmultitype  */
  YYSYMBOL_atmfield = 181,                 /* atmfield  */
  YYSYMBOL_atmvalue = 182,                 /* atmvalue  */
  YYSYMBOL_atmfieldvalue = 183,            /* atmfieldvalue  */
  YYSYMBOL_atmlistvalue = 184,             /* atmlistvalue  */
  YYSYMBOL_mtp2type = 185,                 /* mtp2type  */
  YYSYMBOL_mtp3field = 186,                /* mtp3field  */
  YYSYMBOL_mtp3value = 187,                /* mtp3value  */
  YYSYMBOL_mtp3fieldvalue = 188,           /* mtp3fieldvalue  */
  YYSYMBOL_mtp3listvalue = 189             /* mtp3listvalue  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   759

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  142
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  226
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  301

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   379


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   124,     2,     2,     2,   140,   126,     2,
     133,   132,   129,   127,     2,   128,     2,   130,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   139,     2,
     136,   135,   134,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   137,     2,   138,   141,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   125,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   131
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   424,   424,   428,   430,   432,   433,   434,   435,   436,
     438,   440,   442,   443,   445,   447,   448,   450,   452,   471,
     482,   493,   494,   495,   497,   499,   501,   502,   503,   505,
     507,   509,   510,   512,   513,   514,   515,   516,   524,   526,
     527,   528,   529,   531,   533,   534,   535,   536,   537,   538,
     541,   542,   545,   546,   547,   548,   549,   550,   551,   552,
     553,   554,   555,   556,   559,   560,   561,   562,   565,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   607,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   630,
     631,   632,   633,   658,   659,   660,   661,   662,   663,   666,
     671,   674,   678,   681,   687,   696,   702,   725,   742,   743,
     767,   770,   771,   787,   788,   791,   794,   795,   796,   798,
     799,   800,   802,   803,   805,   806,   807,   808,   809,   810,
     811,   812,   813,   814,   815,   816,   817,   818,   819,   821,
     822,   823,   824,   825,   827,   828,   830,   831,   832,   833,
     834,   835,   836,   838,   839,   840,   841,   844,   845,   847,
     848,   849,   850,   852,   859,   860,   863,   864,   865,   866,
     867,   868,   871,   872,   873,   874,   875,   876,   877,   878,
     880,   881,   882,   883,   885,   898,   899
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "DST", "SRC", "HOST",
  "GATEWAY", "NET", "NETMASK", "PORT", "PORTRANGE", "LESS", "GREATER",
  "PROTO", "PROTOCHAIN", "CBYTE", "ARP", "RARP", "IP", "SCTP", "TCP",
  "UDP", "ICMP", "IGMP", "IGRP", "PIM", "VRRP", "CARP", "ATALK", "AARP",
  "DECNET", "LAT", "SCA", "MOPRC", "MOPDL", "TK_BROADCAST", "TK_MULTICAST",
  "NUM", "INBOUND", "OUTBOUND", "IFINDEX", "PF_IFNAME", "PF_RSET",
  "PF_RNR", "PF_SRNR", "PF_REASON", "PF_ACTION", "TYPE", "SUBTYPE", "DIR",
  "ADDR1", "ADDR2", "ADDR3", "ADDR4", "RA", "TA", "LINK", "GEQ", "LEQ",
  "NEQ", "ID", "EID", "HID", "HID6", "AID", "LSH", "RSH", "LEN", "IPV6",
  "ICMPV6", "AH", "ESP", "VLAN", "MPLS", "PPPOED", "PPPOES", "GENEVE",
  "BATADV", "ISO", "ESIS", "CLNP", "ISIS", "L1", "L2", "IIH", "LSP", "SNP",
  "CSNP", "PSNP", "STP", "IPX", "NETBEUI", "LANE", "LLC", "METAC", "BCC",
  "SC", "ILMIC", "OAMF4EC", "OAMF4SC", "OAM", "OAMF4", "CONNECTMSG",
  "METACONNECT", "VPI", "VCI", "RADIO", "FISU", "LSSU", "MSU", "HFISU",
  "HLSSU", "HMSU", "SIO", "OPC", "DPC", "SLS", "HSIO", "HOPC", "HDPC",
  "HSLS", "LEX_ERROR", "OR", "AND", "'!'", "'|'", "'&'", "'+'", "'-'",
  "'*'", "'/'", "UMINUS", "')'", "'('", "'>'", "'='", "'<'", "'['", "']'",
  "':'", "'%'", "'^'", "$accept", "prog", "null", "expr", "and", "or",
  "id", "nid", "not", "paren", "pid", "qid", "term", "head", "rterm",
  "pqual", "dqual", "aqual", "ndaqual", "pname", "other", "pbatadv",
  "pfvar", "p80211", "type", "subtype", "type_subtype", "pllc", "dir",
  "reason", "action", "relop", "irelop", "arth", "narth", "byteop", "pnum",
  "atmtype", "atmmultitype", "atmfield", "atmvalue", "atmfieldvalue",
  "atmlistvalue", "mtp2type", "mtp3field", "mtp3value", "mtp3fieldvalue",
  "mtp3listvalue", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-212)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-42)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -212,    17,   226,  -212,   -17,     5,    42,  -212,  -212,  -212,
    -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
    -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,    46,
      30,    49,    95,   104,    -3,    85,  -212,  -212,  -212,  -212,
    -212,  -212,   -22,   -22,  -212,   -22,   -22,   -22,  -212,  -212,
    -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
    -212,  -212,  -212,    20,  -212,  -212,  -212,  -212,  -212,  -212,
    -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
    -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
    -212,  -212,   582,  -212,   -87,   464,   464,  -212,   155,  -212,
      18,    12,  -212,  -212,  -212,   564,  -212,  -212,  -212,  -212,
      62,  -212,   150,  -212,  -212,    37,  -212,  -212,  -212,  -212,
    -212,  -212,  -212,  -212,  -212,  -212,   -22,  -212,  -212,  -212,
    -212,  -212,   -27,  -212,  -212,   582,    16,   -92,  -212,  -212,
     345,   345,  -212,   -93,    32,    43,  -212,  -212,     3,    50,
    -212,  -212,  -212,   155,   155,  -212,    -5,    47,  -212,  -212,
    -212,  -212,  -212,  -212,  -212,  -212,  -212,     0,   117,     1,
    -212,  -212,  -212,  -212,  -212,  -212,   169,  -212,  -212,  -212,
     582,  -212,  -212,  -212,   582,   582,   582,   582,   582,   582,
     582,   582,  -212,  -212,  -212,   582,   582,   582,   582,  -212,
     144,   147,   148,  -212,  -212,  -212,   149,   151,   154,  -212,
    -212,  -212,  -212,  -212,  -212,  -212,   156,    43,  -212,  -212,
     609,  -212,   345,   345,  -212,    14,  -212,  -212,  -212,  -212,
    -212,   132,   162,   163,  -212,  -212,    69,   -87,    43,   198,
     199,   201,   202,  -212,  -212,   158,  -212,  -212,  -212,  -212,
    -212,  -212,   591,   -52,   -52,   614,   618,   -14,   -14,   -92,
     -92,   609,   609,   609,   609,  -212,   -48,  -212,  -212,  -212,
     -10,  -212,  -212,  -212,   -41,  -212,  -212,  -212,  -212,   155,
     155,  -212,  -212,  -212,  -212,    27,  -212,   173,  -212,   144,
    -212,   149,  -212,  -212,  -212,  -212,  -212,    73,  -212,  -212,
    -212
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,    51,     1,     0,     0,     0,    71,    72,    70,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    88,    87,   184,   113,   114,     0,
       0,     0,     0,     0,     0,     0,    69,   178,    89,    90,
      91,    92,   117,   119,   120,   122,   124,   129,    93,    94,
     103,    95,    96,    97,    98,    99,   100,   102,   101,   104,
     105,   106,   186,   148,   187,   188,   191,   192,   189,   190,
     193,   194,   195,   196,   197,   198,   107,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,    24,     0,    25,     2,    51,    51,     5,     0,    31,
       0,    50,    44,   126,   128,     0,   163,   162,    45,    46,
       0,    48,     0,   110,   111,     0,   115,   133,   134,   135,
     136,   153,   154,   137,   155,   138,     0,   116,   118,   121,
     123,   125,   130,   150,   149,     0,     0,   176,    11,    10,
      51,    51,    32,     0,   163,   162,    15,    21,    18,    20,
      22,    39,    12,     0,     0,    13,    53,    52,    64,    68,
      65,    66,    67,    36,    37,   108,   109,     0,     0,     0,
      58,    59,    60,    61,    62,    63,    34,    35,    38,   127,
       0,   157,   159,   161,     0,     0,     0,     0,     0,     0,
       0,     0,   156,   158,   160,     0,     0,     0,     0,   203,
       0,     0,     0,    47,   199,   224,     0,     0,     0,    49,
     220,   180,   179,   182,   183,   181,     0,     0,   132,   131,
       0,     7,    51,    51,     6,   162,     9,     8,    40,   177,
     185,     0,     0,     0,    23,    26,    30,     0,    29,     0,
       0,     0,     0,   143,   144,   140,   147,   141,   151,   152,
     142,    33,     0,   174,   175,   172,   171,   166,   167,   168,
     169,   170,   173,    42,    43,   204,     0,   200,   201,   225,
       0,   221,   222,   112,   162,    17,    16,    19,    14,     0,
       0,    55,    57,    54,    56,     0,   164,     0,   202,     0,
     223,     0,    27,    28,   145,   146,   139,     0,   205,   226,
     165
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -212,  -212,  -212,   210,   -24,  -211,   -90,  -138,     2,    -2,
    -212,  -212,   -94,  -212,  -212,  -212,  -212,    38,  -212,     7,
    -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
    -212,    13,    19,   -30,   -83,  -212,   -40,  -212,  -212,  -212,
    -212,  -182,  -212,  -212,  -212,  -212,  -187,  -212
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,   143,   140,   141,   234,   152,   153,   135,
     236,   237,    97,    98,    99,   100,   176,   177,   178,   136,
     102,   131,   103,   179,   245,   296,   247,   104,   250,   123,
     125,   197,   198,   105,   106,   216,   107,   108,   109,   110,
     203,   204,   266,   111,   112,   209,   210,   270
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      96,   142,   127,   128,    95,   129,   130,   132,   151,   101,
      26,   231,   -41,   144,   -13,    26,   235,     3,   265,   269,
     113,   156,   157,   158,   159,   160,   280,   161,   162,   138,
     139,   163,   164,   218,   121,   138,   139,   243,   248,   228,
     126,   126,   114,   126,   126,   126,   224,   227,   195,   196,
     221,   226,   144,   165,   166,   289,   145,   122,   155,   291,
     244,   249,   137,   133,   294,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   138,   188,   189,   190,   191,   115,
     134,   -29,   -29,   116,   288,   235,   217,   295,   195,   196,
     117,   230,   219,    96,    96,   145,   154,    95,    95,   199,
     225,   225,   101,   101,   299,   220,    93,   298,   200,   118,
     206,    93,   138,   155,   238,   190,   191,   239,   240,   181,
     182,   183,   290,   201,   126,   207,   195,   196,   142,   202,
     126,   208,   119,   232,   -41,   -41,   -13,   -13,   223,   223,
     144,   120,   222,   222,   -41,   124,   -13,   101,   101,   180,
     252,   154,   126,   180,   253,   254,   255,   256,   257,   258,
     259,   260,   211,   212,   229,   261,   262,   263,   264,   241,
     242,   213,   214,   215,   158,   230,   160,   246,   161,   162,
     233,   199,   225,   274,   267,   268,   205,   205,   271,   292,
     293,   272,    26,   273,   275,    93,   192,   193,   194,   276,
     277,   278,   281,   282,   283,   284,   285,   181,   182,   183,
     297,   300,    94,   279,   251,   146,   147,   148,   149,   150,
     223,    96,     0,     0,   222,   222,    -3,     0,     0,   101,
     101,     0,     0,     0,     0,     0,     0,     4,     5,   155,
     155,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,     0,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,     0,     0,   154,   154,    91,
       0,     0,    36,    93,   192,   193,   194,     0,    93,     0,
       0,     0,     0,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,     0,     0,     0,
      91,     0,     0,     0,    92,     0,     4,     5,     0,    93,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,     0,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    36,     0,     0,     0,   146,   147,   148,   149,   150,
       0,     0,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,     0,     0,     0,    91,
       0,     0,     0,    92,     0,     4,     5,     0,    93,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
       0,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      36,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,     0,     0,     0,    91,     0,
       0,     0,    92,     0,     0,     0,     0,    93,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,     0,    26,
       0,   181,   182,   183,     0,     0,     0,     0,     0,   184,
     185,     0,     0,     0,     0,     0,     0,     0,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
      38,    39,    40,    41,     0,     0,   184,   185,     0,     0,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,   184,   185,     0,     0,     0,   184,
     185,     0,     0,   184,   185,     0,     0,     0,    76,   186,
     187,   188,   189,   190,   191,     0,     0,     0,   192,   193,
     194,     0,     0,     0,   195,   196,     0,     0,     0,     0,
      92,     0,     0,     0,     0,    93,   186,   187,   188,   189,
     190,   191,     0,     0,     0,     0,     0,     0,     0,   286,
     287,   195,   196,     0,   186,   187,   188,   189,   190,   191,
     187,   188,   189,   190,   191,   188,   189,   190,   191,   195,
     196,     0,     0,     0,   195,   196,     0,     0,   195,   196
};

static const yytype_int16 yycheck[] =
{
       2,    95,    42,    43,     2,    45,    46,    47,    98,     2,
      37,     8,     0,    96,     0,    37,   154,     0,   200,   206,
      37,     3,     4,     5,     6,     7,   237,     9,    10,   122,
     123,    13,    14,    60,    37,   122,   123,    37,    37,   132,
      42,    43,    37,    45,    46,    47,   140,   141,   140,   141,
     140,   141,   135,    35,    36,   266,    96,    60,    98,   270,
      60,    60,    92,    43,    37,    47,    48,    49,    50,    51,
      52,    53,    54,    55,   122,   127,   128,   129,   130,    37,
      60,   122,   123,    37,   132,   223,   126,    60,   140,   141,
      60,   132,   132,    95,    96,   135,    98,    95,    96,    37,
     140,   141,    95,    96,   291,   135,   133,   289,   110,    60,
     112,   133,   122,   153,   154,   129,   130,   122,   123,    57,
      58,    59,   132,   110,   126,   112,   140,   141,   222,   110,
     132,   112,    37,   130,   122,   123,   122,   123,   140,   141,
     223,    37,   140,   141,   132,    60,   132,   140,   141,   137,
     180,   153,   154,   137,   184,   185,   186,   187,   188,   189,
     190,   191,   125,   126,   132,   195,   196,   197,   198,   122,
     123,   134,   135,   136,     5,   132,     7,    60,     9,    10,
     130,    37,   222,   223,    37,    37,    37,    37,    37,   279,
     280,    37,    37,    37,    62,   133,   134,   135,   136,    37,
      37,   132,     4,     4,     3,     3,    48,    57,    58,    59,
      37,   138,     2,   237,   176,    60,    61,    62,    63,    64,
     222,   223,    -1,    -1,   222,   223,     0,    -1,    -1,   222,
     223,    -1,    -1,    -1,    -1,    -1,    -1,    11,    12,   279,
     280,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    -1,   279,   280,   124,
      -1,    -1,    56,   133,   134,   135,   136,    -1,   133,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,    -1,    -1,    -1,
     124,    -1,    -1,    -1,   128,    -1,    11,    12,    -1,   133,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    -1,    60,    61,    62,    63,    64,
      -1,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    -1,    -1,    -1,   124,
      -1,    -1,    -1,   128,    -1,    11,    12,    -1,   133,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,
      -1,    -1,   128,    -1,    -1,    -1,    -1,   133,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    37,
      -1,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,    65,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    70,    71,    -1,    -1,    65,    66,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    65,    66,    -1,    -1,    -1,    65,
      66,    -1,    -1,    65,    66,    -1,    -1,    -1,   106,   125,
     126,   127,   128,   129,   130,    -1,    -1,    -1,   134,   135,
     136,    -1,    -1,    -1,   140,   141,    -1,    -1,    -1,    -1,
     128,    -1,    -1,    -1,    -1,   133,   125,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,    -1,   125,   126,   127,   128,   129,   130,
     126,   127,   128,   129,   130,   127,   128,   129,   130,   140,
     141,    -1,    -1,    -1,   140,   141,    -1,    -1,   140,   141
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   143,   144,     0,    11,    12,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    56,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   124,   128,   133,   145,   150,   151,   154,   155,   156,
     157,   161,   162,   164,   169,   175,   176,   178,   179,   180,
     181,   185,   186,    37,    37,    37,    37,    60,    60,    37,
      37,    37,    60,   171,    60,   172,   151,   178,   178,   178,
     178,   163,   178,    43,    60,   151,   161,   175,   122,   123,
     146,   147,   154,   145,   176,   178,    60,    61,    62,    63,
      64,   148,   149,   150,   151,   178,     3,     4,     5,     6,
       7,     9,    10,    13,    14,    35,    36,    47,    48,    49,
      50,    51,    52,    53,    54,    55,   158,   159,   160,   165,
     137,    57,    58,    59,    65,    66,   125,   126,   127,   128,
     129,   130,   134,   135,   136,   140,   141,   173,   174,    37,
     151,   173,   174,   182,   183,    37,   151,   173,   174,   187,
     188,   125,   126,   134,   135,   136,   177,   178,    60,   178,
     175,   148,   150,   151,   154,   178,   148,   154,   132,   132,
     132,     8,   130,   130,   148,   149,   152,   153,   178,   122,
     123,   122,   123,    37,    60,   166,    60,   168,    37,    60,
     170,   159,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   183,   184,    37,    37,   188,
     189,    37,    37,    37,   178,    62,    37,    37,   132,   146,
     147,     4,     4,     3,     3,    48,   138,   139,   132,   147,
     132,   147,   148,   148,    37,    60,   167,    37,   183,   188,
     138
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   142,   143,   143,   144,   145,   145,   145,   145,   145,
     146,   147,   148,   148,   148,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   150,   151,   152,   152,   152,   153,
     153,   154,   154,   155,   155,   155,   155,   155,   155,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     157,   157,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   159,   159,   159,   159,   160,   161,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   161,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   163,
     163,   163,   163,   164,   164,   164,   164,   164,   164,   165,
     165,   165,   165,   166,   166,   167,   167,   168,   169,   169,
     169,   170,   170,   171,   171,   172,   173,   173,   173,   174,
     174,   174,   175,   175,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   177,
     177,   177,   177,   177,   178,   178,   179,   179,   179,   179,
     179,   179,   179,   180,   180,   180,   180,   181,   181,   182,
     182,   182,   182,   183,   184,   184,   185,   185,   185,   185,
     185,   185,   186,   186,   186,   186,   186,   186,   186,   186,
     187,   187,   187,   187,   188,   189,   189
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     0,     1,     3,     3,     3,     3,
       1,     1,     1,     1,     3,     1,     3,     3,     1,     3,
       1,     1,     1,     2,     1,     1,     1,     3,     3,     1,
       1,     1,     2,     3,     2,     2,     2,     2,     2,     2,
       3,     1,     3,     3,     1,     1,     1,     2,     1,     2,
       1,     0,     1,     1,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     4,     1,     1,     2,     2,     1,     2,     1,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     0,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     4,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     6,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     3,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     3,     1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (yyscanner, cstate, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, yyscanner, cstate); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void *yyscanner, compiler_state_t *cstate)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yyscanner);
  YY_USE (cstate);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void *yyscanner, compiler_state_t *cstate)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, yyscanner, cstate);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, void *yyscanner, compiler_state_t *cstate)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], yyscanner, cstate);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, yyscanner, cstate); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, void *yyscanner, compiler_state_t *cstate)
{
  YY_USE (yyvaluep);
  YY_USE (yyscanner);
  YY_USE (cstate);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (void *yyscanner, compiler_state_t *cstate)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, yyscanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* prog: null expr  */
#line 425 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
{
	CHECK_INT_VAL(finish_parse(cstate, (yyvsp[0].blk).b));
}
#line 1901 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 4: /* null: %empty  */
#line 430 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.blk).q = qerr; }
#line 1907 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 6: /* expr: expr and term  */
#line 433 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { gen_and((yyvsp[-2].blk).b, (yyvsp[0].blk).b); (yyval.blk) = (yyvsp[0].blk); }
#line 1913 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 7: /* expr: expr and id  */
#line 434 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { gen_and((yyvsp[-2].blk).b, (yyvsp[0].blk).b); (yyval.blk) = (yyvsp[0].blk); }
#line 1919 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 8: /* expr: expr or term  */
#line 435 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { gen_or((yyvsp[-2].blk).b, (yyvsp[0].blk).b); (yyval.blk) = (yyvsp[0].blk); }
#line 1925 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 9: /* expr: expr or id  */
#line 436 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { gen_or((yyvsp[-2].blk).b, (yyvsp[0].blk).b); (yyval.blk) = (yyvsp[0].blk); }
#line 1931 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 10: /* and: AND  */
#line 438 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.blk) = (yyvsp[-1].blk); }
#line 1937 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 11: /* or: OR  */
#line 440 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.blk) = (yyvsp[-1].blk); }
#line 1943 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 13: /* id: pnum  */
#line 443 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.blk).b = gen_ncode(cstate, NULL, (yyvsp[0].h),
						   (yyval.blk).q = (yyvsp[-1].blk).q))); }
#line 1950 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 14: /* id: paren pid ')'  */
#line 445 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.blk) = (yyvsp[-1].blk); }
#line 1956 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 15: /* nid: ID  */
#line 447 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL((yyvsp[0].s)); CHECK_PTR_VAL(((yyval.blk).b = gen_scode(cstate, (yyvsp[0].s), (yyval.blk).q = (yyvsp[-1].blk).q))); }
#line 1962 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 16: /* nid: HID '/' NUM  */
#line 448 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL((yyvsp[-2].s)); CHECK_PTR_VAL(((yyval.blk).b = gen_mcode(cstate, (yyvsp[-2].s), NULL, (yyvsp[0].h),
				    (yyval.blk).q = (yyvsp[-3].blk).q))); }
#line 1969 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 17: /* nid: HID NETMASK HID  */
#line 450 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL((yyvsp[-2].s)); CHECK_PTR_VAL(((yyval.blk).b = gen_mcode(cstate, (yyvsp[-2].s), (yyvsp[0].s), 0,
				    (yyval.blk).q = (yyvsp[-3].blk).q))); }
#line 1976 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 18: /* nid: HID  */
#line 452 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                {
				  CHECK_PTR_VAL((yyvsp[0].s));
				  /* Decide how to parse HID based on proto */
				  (yyval.blk).q = (yyvsp[-1].blk).q;
				  if ((yyval.blk).q.addr == Q_PORT) {
					bpf_set_error(cstate, "'port' modifier applied to ip host");
					YYABORT;
				  } else if ((yyval.blk).q.addr == Q_PORTRANGE) {
					bpf_set_error(cstate, "'portrange' modifier applied to ip host");
					YYABORT;
				  } else if ((yyval.blk).q.addr == Q_PROTO) {
					bpf_set_error(cstate, "'proto' modifier applied to ip host");
					YYABORT;
				  } else if ((yyval.blk).q.addr == Q_PROTOCHAIN) {
					bpf_set_error(cstate, "'protochain' modifier applied to ip host");
					YYABORT;
				  }
				  CHECK_PTR_VAL(((yyval.blk).b = gen_ncode(cstate, (yyvsp[0].s), 0, (yyval.blk).q)));
				}
#line 2000 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 19: /* nid: HID6 '/' NUM  */
#line 471 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                {
				  CHECK_PTR_VAL((yyvsp[-2].s));
#ifdef INET6
				  CHECK_PTR_VAL(((yyval.blk).b = gen_mcode6(cstate, (yyvsp[-2].s), NULL, (yyvsp[0].h),
				    (yyval.blk).q = (yyvsp[-3].blk).q)));
#else
				  bpf_set_error(cstate, "'ip6addr/prefixlen' not supported "
					"in this configuration");
				  YYABORT;
#endif /*INET6*/
				}
#line 2016 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 20: /* nid: HID6  */
#line 482 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                {
				  CHECK_PTR_VAL((yyvsp[0].s));
#ifdef INET6
				  CHECK_PTR_VAL(((yyval.blk).b = gen_mcode6(cstate, (yyvsp[0].s), 0, 128,
				    (yyval.blk).q = (yyvsp[-1].blk).q)));
#else
				  bpf_set_error(cstate, "'ip6addr' not supported "
					"in this configuration");
				  YYABORT;
#endif /*INET6*/
				}
#line 2032 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 21: /* nid: EID  */
#line 493 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL((yyvsp[0].s)); CHECK_PTR_VAL(((yyval.blk).b = gen_ecode(cstate, (yyvsp[0].s), (yyval.blk).q = (yyvsp[-1].blk).q))); }
#line 2038 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 22: /* nid: AID  */
#line 494 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL((yyvsp[0].s)); CHECK_PTR_VAL(((yyval.blk).b = gen_acode(cstate, (yyvsp[0].s), (yyval.blk).q = (yyvsp[-1].blk).q))); }
#line 2044 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 23: /* nid: not id  */
#line 495 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { gen_not((yyvsp[0].blk).b); (yyval.blk) = (yyvsp[0].blk); }
#line 2050 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 24: /* not: '!'  */
#line 497 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.blk) = (yyvsp[-1].blk); }
#line 2056 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 25: /* paren: '('  */
#line 499 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.blk) = (yyvsp[-1].blk); }
#line 2062 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 27: /* pid: qid and id  */
#line 502 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { gen_and((yyvsp[-2].blk).b, (yyvsp[0].blk).b); (yyval.blk) = (yyvsp[0].blk); }
#line 2068 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 28: /* pid: qid or id  */
#line 503 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { gen_or((yyvsp[-2].blk).b, (yyvsp[0].blk).b); (yyval.blk) = (yyvsp[0].blk); }
#line 2074 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 29: /* qid: pnum  */
#line 505 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.blk).b = gen_ncode(cstate, NULL, (yyvsp[0].h),
						   (yyval.blk).q = (yyvsp[-1].blk).q))); }
#line 2081 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 32: /* term: not term  */
#line 510 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { gen_not((yyvsp[0].blk).b); (yyval.blk) = (yyvsp[0].blk); }
#line 2087 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 33: /* head: pqual dqual aqual  */
#line 512 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { QSET((yyval.blk).q, (yyvsp[-2].i), (yyvsp[-1].i), (yyvsp[0].i)); }
#line 2093 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 34: /* head: pqual dqual  */
#line 513 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { QSET((yyval.blk).q, (yyvsp[-1].i), (yyvsp[0].i), Q_DEFAULT); }
#line 2099 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 35: /* head: pqual aqual  */
#line 514 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { QSET((yyval.blk).q, (yyvsp[-1].i), Q_DEFAULT, (yyvsp[0].i)); }
#line 2105 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 36: /* head: pqual PROTO  */
#line 515 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { QSET((yyval.blk).q, (yyvsp[-1].i), Q_DEFAULT, Q_PROTO); }
#line 2111 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 37: /* head: pqual PROTOCHAIN  */
#line 516 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                {
#ifdef NO_PROTOCHAIN
				  bpf_set_error(cstate, "protochain not supported");
				  YYABORT;
#else
				  QSET((yyval.blk).q, (yyvsp[-1].i), Q_DEFAULT, Q_PROTOCHAIN);
#endif
				}
#line 2124 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 38: /* head: pqual ndaqual  */
#line 524 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { QSET((yyval.blk).q, (yyvsp[-1].i), Q_DEFAULT, (yyvsp[0].i)); }
#line 2130 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 39: /* rterm: head id  */
#line 526 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.blk) = (yyvsp[0].blk); }
#line 2136 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 40: /* rterm: paren expr ')'  */
#line 527 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.blk).b = (yyvsp[-1].blk).b; (yyval.blk).q = (yyvsp[-2].blk).q; }
#line 2142 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 41: /* rterm: pname  */
#line 528 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.blk).b = gen_proto_abbrev(cstate, (yyvsp[0].i)))); (yyval.blk).q = qerr; }
#line 2148 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 42: /* rterm: arth relop arth  */
#line 529 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.blk).b = gen_relation(cstate, (yyvsp[-1].i), (yyvsp[-2].a), (yyvsp[0].a), 0)));
				  (yyval.blk).q = qerr; }
#line 2155 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 43: /* rterm: arth irelop arth  */
#line 531 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.blk).b = gen_relation(cstate, (yyvsp[-1].i), (yyvsp[-2].a), (yyvsp[0].a), 1)));
				  (yyval.blk).q = qerr; }
#line 2162 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 44: /* rterm: other  */
#line 533 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.blk).b = (yyvsp[0].rblk); (yyval.blk).q = qerr; }
#line 2168 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 45: /* rterm: atmtype  */
#line 534 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.blk).b = gen_atmtype_abbrev(cstate, (yyvsp[0].i)))); (yyval.blk).q = qerr; }
#line 2174 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 46: /* rterm: atmmultitype  */
#line 535 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.blk).b = gen_atmmulti_abbrev(cstate, (yyvsp[0].i)))); (yyval.blk).q = qerr; }
#line 2180 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 47: /* rterm: atmfield atmvalue  */
#line 536 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.blk).b = (yyvsp[0].blk).b; (yyval.blk).q = qerr; }
#line 2186 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 48: /* rterm: mtp2type  */
#line 537 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.blk).b = gen_mtp2type_abbrev(cstate, (yyvsp[0].i)))); (yyval.blk).q = qerr; }
#line 2192 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 49: /* rterm: mtp3field mtp3value  */
#line 538 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.blk).b = (yyvsp[0].blk).b; (yyval.blk).q = qerr; }
#line 2198 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 51: /* pqual: %empty  */
#line 542 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_DEFAULT; }
#line 2204 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 52: /* dqual: SRC  */
#line 545 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_SRC; }
#line 2210 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 53: /* dqual: DST  */
#line 546 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_DST; }
#line 2216 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 54: /* dqual: SRC OR DST  */
#line 547 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_OR; }
#line 2222 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 55: /* dqual: DST OR SRC  */
#line 548 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_OR; }
#line 2228 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 56: /* dqual: SRC AND DST  */
#line 549 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_AND; }
#line 2234 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 57: /* dqual: DST AND SRC  */
#line 550 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_AND; }
#line 2240 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 58: /* dqual: ADDR1  */
#line 551 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_ADDR1; }
#line 2246 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 59: /* dqual: ADDR2  */
#line 552 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_ADDR2; }
#line 2252 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 60: /* dqual: ADDR3  */
#line 553 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_ADDR3; }
#line 2258 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 61: /* dqual: ADDR4  */
#line 554 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_ADDR4; }
#line 2264 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 62: /* dqual: RA  */
#line 555 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_RA; }
#line 2270 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 63: /* dqual: TA  */
#line 556 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_TA; }
#line 2276 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 64: /* aqual: HOST  */
#line 559 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_HOST; }
#line 2282 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 65: /* aqual: NET  */
#line 560 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_NET; }
#line 2288 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 66: /* aqual: PORT  */
#line 561 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_PORT; }
#line 2294 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 67: /* aqual: PORTRANGE  */
#line 562 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_PORTRANGE; }
#line 2300 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 68: /* ndaqual: GATEWAY  */
#line 565 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_GATEWAY; }
#line 2306 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 69: /* pname: LINK  */
#line 567 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_LINK; }
#line 2312 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 70: /* pname: IP  */
#line 568 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_IP; }
#line 2318 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 71: /* pname: ARP  */
#line 569 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_ARP; }
#line 2324 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 72: /* pname: RARP  */
#line 570 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_RARP; }
#line 2330 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 73: /* pname: SCTP  */
#line 571 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_SCTP; }
#line 2336 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 74: /* pname: TCP  */
#line 572 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_TCP; }
#line 2342 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 75: /* pname: UDP  */
#line 573 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_UDP; }
#line 2348 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 76: /* pname: ICMP  */
#line 574 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_ICMP; }
#line 2354 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 77: /* pname: IGMP  */
#line 575 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_IGMP; }
#line 2360 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 78: /* pname: IGRP  */
#line 576 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_IGRP; }
#line 2366 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 79: /* pname: PIM  */
#line 577 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_PIM; }
#line 2372 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 80: /* pname: VRRP  */
#line 578 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_VRRP; }
#line 2378 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 81: /* pname: CARP  */
#line 579 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_CARP; }
#line 2384 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 82: /* pname: ATALK  */
#line 580 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_ATALK; }
#line 2390 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 83: /* pname: AARP  */
#line 581 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_AARP; }
#line 2396 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 84: /* pname: DECNET  */
#line 582 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_DECNET; }
#line 2402 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 85: /* pname: LAT  */
#line 583 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_LAT; }
#line 2408 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 86: /* pname: SCA  */
#line 584 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_SCA; }
#line 2414 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 87: /* pname: MOPDL  */
#line 585 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_MOPDL; }
#line 2420 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 88: /* pname: MOPRC  */
#line 586 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_MOPRC; }
#line 2426 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 89: /* pname: IPV6  */
#line 587 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_IPV6; }
#line 2432 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 90: /* pname: ICMPV6  */
#line 588 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_ICMPV6; }
#line 2438 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 91: /* pname: AH  */
#line 589 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_AH; }
#line 2444 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 92: /* pname: ESP  */
#line 590 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_ESP; }
#line 2450 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 93: /* pname: ISO  */
#line 591 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_ISO; }
#line 2456 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 94: /* pname: ESIS  */
#line 592 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_ESIS; }
#line 2462 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 95: /* pname: ISIS  */
#line 593 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_ISIS; }
#line 2468 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 96: /* pname: L1  */
#line 594 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_ISIS_L1; }
#line 2474 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 97: /* pname: L2  */
#line 595 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_ISIS_L2; }
#line 2480 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 98: /* pname: IIH  */
#line 596 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_ISIS_IIH; }
#line 2486 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 99: /* pname: LSP  */
#line 597 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_ISIS_LSP; }
#line 2492 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 100: /* pname: SNP  */
#line 598 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_ISIS_SNP; }
#line 2498 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 101: /* pname: PSNP  */
#line 599 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_ISIS_PSNP; }
#line 2504 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 102: /* pname: CSNP  */
#line 600 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_ISIS_CSNP; }
#line 2510 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 103: /* pname: CLNP  */
#line 601 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_CLNP; }
#line 2516 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 104: /* pname: STP  */
#line 602 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_STP; }
#line 2522 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 105: /* pname: IPX  */
#line 603 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_IPX; }
#line 2528 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 106: /* pname: NETBEUI  */
#line 604 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_NETBEUI; }
#line 2534 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 107: /* pname: RADIO  */
#line 605 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = Q_RADIO; }
#line 2540 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 108: /* other: pqual TK_BROADCAST  */
#line 607 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.rblk) = gen_broadcast(cstate, (yyvsp[-1].i)))); }
#line 2546 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 109: /* other: pqual TK_MULTICAST  */
#line 608 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.rblk) = gen_multicast(cstate, (yyvsp[-1].i)))); }
#line 2552 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 110: /* other: LESS NUM  */
#line 609 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.rblk) = gen_less(cstate, (yyvsp[0].h)))); }
#line 2558 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 111: /* other: GREATER NUM  */
#line 610 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.rblk) = gen_greater(cstate, (yyvsp[0].h)))); }
#line 2564 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 112: /* other: CBYTE NUM byteop NUM  */
#line 611 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.rblk) = gen_byteop(cstate, (yyvsp[-1].i), (yyvsp[-2].h), (yyvsp[0].h)))); }
#line 2570 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 113: /* other: INBOUND  */
#line 612 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.rblk) = gen_inbound(cstate, 0))); }
#line 2576 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 114: /* other: OUTBOUND  */
#line 613 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.rblk) = gen_inbound(cstate, 1))); }
#line 2582 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 115: /* other: IFINDEX NUM  */
#line 614 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.rblk) = gen_ifindex(cstate, (yyvsp[0].h)))); }
#line 2588 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 116: /* other: VLAN pnum  */
#line 615 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.rblk) = gen_vlan(cstate, (yyvsp[0].h), 1))); }
#line 2594 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 117: /* other: VLAN  */
#line 616 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.rblk) = gen_vlan(cstate, 0, 0))); }
#line 2600 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 118: /* other: MPLS pnum  */
#line 617 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.rblk) = gen_mpls(cstate, (yyvsp[0].h), 1))); }
#line 2606 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 119: /* other: MPLS  */
#line 618 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.rblk) = gen_mpls(cstate, 0, 0))); }
#line 2612 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 120: /* other: PPPOED  */
#line 619 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.rblk) = gen_pppoed(cstate))); }
#line 2618 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 121: /* other: PPPOES pnum  */
#line 620 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.rblk) = gen_pppoes(cstate, (yyvsp[0].h), 1))); }
#line 2624 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 122: /* other: PPPOES  */
#line 621 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.rblk) = gen_pppoes(cstate, 0, 0))); }
#line 2630 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 123: /* other: GENEVE pnum  */
#line 622 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.rblk) = gen_geneve(cstate, (yyvsp[0].h), 1))); }
#line 2636 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 124: /* other: GENEVE  */
#line 623 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.rblk) = gen_geneve(cstate, 0, 0))); }
#line 2642 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 125: /* other: BATADV pbatadv  */
#line 624 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.rblk) = (yyvsp[0].rblk); }
#line 2648 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 126: /* other: pfvar  */
#line 625 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.rblk) = (yyvsp[0].rblk); }
#line 2654 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 127: /* other: pqual p80211  */
#line 626 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.rblk) = (yyvsp[0].rblk); }
#line 2660 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 128: /* other: pllc  */
#line 627 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.rblk) = (yyvsp[0].rblk); }
#line 2666 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 129: /* pbatadv: %empty  */
#line 630 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                        { CHECK_PTR_VAL(((yyval.rblk) = gen_batadv(cstate, 0, 0, 0, 0))); }
#line 2672 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 130: /* pbatadv: pnum  */
#line 631 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                        { CHECK_PTR_VAL(((yyval.rblk) = gen_batadv(cstate, (yyvsp[0].h), 1, 0, 0))); }
#line 2678 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 131: /* pbatadv: pnum pnum  */
#line 632 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                        { CHECK_PTR_VAL(((yyval.rblk) = gen_batadv(cstate, (yyvsp[-1].h), 1, (yyvsp[0].h), 1))); }
#line 2684 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 132: /* pbatadv: pnum ID  */
#line 634 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                {
			int type;

			switch ((yyvsp[-1].h)) {
			case 14:
				type = pcap_nametobatadvtype_v14((yyvsp[0].s));
				break;
			case 15:
				type = pcap_nametobatadvtype_v15((yyvsp[0].s));
				break;
			default:
				bpf_set_error(cstate, "batman-adv compatibility version number %u unsupported", (yyvsp[-1].h));
				YYABORT;
			}

			if (type == PROTO_UNDEF) {
				bpf_set_error(cstate, "invalid batman-adv packet type value \"%s\"", (yyvsp[0].s));
				YYABORT;
			}

			CHECK_PTR_VAL(((yyval.rblk) = gen_batadv(cstate, (yyvsp[-1].h), 1, type, 1)));
		}
#line 2711 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 133: /* pfvar: PF_IFNAME ID  */
#line 658 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL((yyvsp[0].s)); CHECK_PTR_VAL(((yyval.rblk) = gen_pf_ifname(cstate, (yyvsp[0].s)))); }
#line 2717 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 134: /* pfvar: PF_RSET ID  */
#line 659 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL((yyvsp[0].s)); CHECK_PTR_VAL(((yyval.rblk) = gen_pf_ruleset(cstate, (yyvsp[0].s)))); }
#line 2723 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 135: /* pfvar: PF_RNR NUM  */
#line 660 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.rblk) = gen_pf_rnr(cstate, (yyvsp[0].h)))); }
#line 2729 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 136: /* pfvar: PF_SRNR NUM  */
#line 661 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.rblk) = gen_pf_srnr(cstate, (yyvsp[0].h)))); }
#line 2735 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 137: /* pfvar: PF_REASON reason  */
#line 662 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.rblk) = gen_pf_reason(cstate, (yyvsp[0].i)))); }
#line 2741 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 138: /* pfvar: PF_ACTION action  */
#line 663 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.rblk) = gen_pf_action(cstate, (yyvsp[0].i)))); }
#line 2747 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 139: /* p80211: TYPE type SUBTYPE subtype  */
#line 667 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.rblk) = gen_p80211_type(cstate, (yyvsp[-2].i) | (yyvsp[0].i),
					IEEE80211_FC0_TYPE_MASK |
					IEEE80211_FC0_SUBTYPE_MASK)));
				}
#line 2756 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 140: /* p80211: TYPE type  */
#line 671 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.rblk) = gen_p80211_type(cstate, (yyvsp[0].i),
					IEEE80211_FC0_TYPE_MASK)));
				}
#line 2764 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 141: /* p80211: SUBTYPE type_subtype  */
#line 674 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.rblk) = gen_p80211_type(cstate, (yyvsp[0].i),
					IEEE80211_FC0_TYPE_MASK |
					IEEE80211_FC0_SUBTYPE_MASK)));
				}
#line 2773 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 142: /* p80211: DIR dir  */
#line 678 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.rblk) = gen_p80211_fcdir(cstate, (yyvsp[0].i)))); }
#line 2779 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 143: /* type: NUM  */
#line 681 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { if (((yyvsp[0].h) & (~IEEE80211_FC0_TYPE_MASK)) != 0) {
					bpf_set_error(cstate, "invalid 802.11 type value 0x%02x", (yyvsp[0].h));
					YYABORT;
				  }
				  (yyval.i) = (int)(yyvsp[0].h);
				}
#line 2790 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 144: /* type: ID  */
#line 687 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL((yyvsp[0].s));
				  (yyval.i) = str2tok((yyvsp[0].s), ieee80211_types);
				  if ((yyval.i) == -1) {
					bpf_set_error(cstate, "unknown 802.11 type name \"%s\"", (yyvsp[0].s));
					YYABORT;
				  }
				}
#line 2802 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 145: /* subtype: NUM  */
#line 696 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { if (((yyvsp[0].h) & (~IEEE80211_FC0_SUBTYPE_MASK)) != 0) {
					bpf_set_error(cstate, "invalid 802.11 subtype value 0x%02x", (yyvsp[0].h));
					YYABORT;
				  }
				  (yyval.i) = (int)(yyvsp[0].h);
				}
#line 2813 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 146: /* subtype: ID  */
#line 702 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { const struct tok *types = NULL;
				  int i;
				  CHECK_PTR_VAL((yyvsp[0].s));
				  for (i = 0;; i++) {
					if (ieee80211_type_subtypes[i].tok == NULL) {
						/* Ran out of types */
						bpf_set_error(cstate, "unknown 802.11 type");
						YYABORT;
					}
					if ((yyvsp[(-1) - (1)].i) == ieee80211_type_subtypes[i].type) {
						types = ieee80211_type_subtypes[i].tok;
						break;
					}
				  }

				  (yyval.i) = str2tok((yyvsp[0].s), types);
				  if ((yyval.i) == -1) {
					bpf_set_error(cstate, "unknown 802.11 subtype name \"%s\"", (yyvsp[0].s));
					YYABORT;
				  }
				}
#line 2839 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 147: /* type_subtype: ID  */
#line 725 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { int i;
				  CHECK_PTR_VAL((yyvsp[0].s));
				  for (i = 0;; i++) {
					if (ieee80211_type_subtypes[i].tok == NULL) {
						/* Ran out of types */
						bpf_set_error(cstate, "unknown 802.11 type name");
						YYABORT;
					}
					(yyval.i) = str2tok((yyvsp[0].s), ieee80211_type_subtypes[i].tok);
					if ((yyval.i) != -1) {
						(yyval.i) |= ieee80211_type_subtypes[i].type;
						break;
					}
				  }
				}
#line 2859 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 148: /* pllc: LLC  */
#line 742 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.rblk) = gen_llc(cstate))); }
#line 2865 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 149: /* pllc: LLC ID  */
#line 743 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL((yyvsp[0].s));
				  if (pcap_strcasecmp((yyvsp[0].s), "i") == 0) {
					CHECK_PTR_VAL(((yyval.rblk) = gen_llc_i(cstate)));
				  } else if (pcap_strcasecmp((yyvsp[0].s), "s") == 0) {
					CHECK_PTR_VAL(((yyval.rblk) = gen_llc_s(cstate)));
				  } else if (pcap_strcasecmp((yyvsp[0].s), "u") == 0) {
					CHECK_PTR_VAL(((yyval.rblk) = gen_llc_u(cstate)));
				  } else {
					int subtype;

					subtype = str2tok((yyvsp[0].s), llc_s_subtypes);
					if (subtype != -1) {
						CHECK_PTR_VAL(((yyval.rblk) = gen_llc_s_subtype(cstate, subtype)));
					} else {
						subtype = str2tok((yyvsp[0].s), llc_u_subtypes);
						if (subtype == -1) {
							bpf_set_error(cstate, "unknown LLC type name \"%s\"", (yyvsp[0].s));
							YYABORT;
						}
						CHECK_PTR_VAL(((yyval.rblk) = gen_llc_u_subtype(cstate, subtype)));
					}
				  }
				}
#line 2893 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 150: /* pllc: LLC PF_RNR  */
#line 767 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.rblk) = gen_llc_s_subtype(cstate, LLC_RNR))); }
#line 2899 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 151: /* dir: NUM  */
#line 770 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = (int)(yyvsp[0].h); }
#line 2905 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 152: /* dir: ID  */
#line 771 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL((yyvsp[0].s));
				  if (pcap_strcasecmp((yyvsp[0].s), "nods") == 0)
					(yyval.i) = IEEE80211_FC1_DIR_NODS;
				  else if (pcap_strcasecmp((yyvsp[0].s), "tods") == 0)
					(yyval.i) = IEEE80211_FC1_DIR_TODS;
				  else if (pcap_strcasecmp((yyvsp[0].s), "fromds") == 0)
					(yyval.i) = IEEE80211_FC1_DIR_FROMDS;
				  else if (pcap_strcasecmp((yyvsp[0].s), "dstods") == 0)
					(yyval.i) = IEEE80211_FC1_DIR_DSTODS;
				  else {
					bpf_set_error(cstate, "unknown 802.11 direction");
					YYABORT;
				  }
				}
#line 2924 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 153: /* reason: NUM  */
#line 787 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = (yyvsp[0].h); }
#line 2930 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 154: /* reason: ID  */
#line 788 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL((yyvsp[0].s)); CHECK_INT_VAL(((yyval.i) = pfreason_to_num(cstate, (yyvsp[0].s)))); }
#line 2936 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 155: /* action: ID  */
#line 791 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL((yyvsp[0].s)); CHECK_INT_VAL(((yyval.i) = pfaction_to_num(cstate, (yyvsp[0].s)))); }
#line 2942 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 156: /* relop: '>'  */
#line 794 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = BPF_JGT; }
#line 2948 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 157: /* relop: GEQ  */
#line 795 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = BPF_JGE; }
#line 2954 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 158: /* relop: '='  */
#line 796 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = BPF_JEQ; }
#line 2960 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 159: /* irelop: LEQ  */
#line 798 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = BPF_JGT; }
#line 2966 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 160: /* irelop: '<'  */
#line 799 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = BPF_JGE; }
#line 2972 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 161: /* irelop: NEQ  */
#line 800 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = BPF_JEQ; }
#line 2978 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 162: /* arth: pnum  */
#line 802 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.a) = gen_loadi(cstate, (yyvsp[0].h)))); }
#line 2984 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 164: /* narth: pname '[' arth ']'  */
#line 805 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                        { CHECK_PTR_VAL(((yyval.a) = gen_load(cstate, (yyvsp[-3].i), (yyvsp[-1].a), 1))); }
#line 2990 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 165: /* narth: pname '[' arth ':' NUM ']'  */
#line 806 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                        { CHECK_PTR_VAL(((yyval.a) = gen_load(cstate, (yyvsp[-5].i), (yyvsp[-3].a), (yyvsp[-1].h)))); }
#line 2996 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 166: /* narth: arth '+' arth  */
#line 807 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                        { CHECK_PTR_VAL(((yyval.a) = gen_arth(cstate, BPF_ADD, (yyvsp[-2].a), (yyvsp[0].a)))); }
#line 3002 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 167: /* narth: arth '-' arth  */
#line 808 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                        { CHECK_PTR_VAL(((yyval.a) = gen_arth(cstate, BPF_SUB, (yyvsp[-2].a), (yyvsp[0].a)))); }
#line 3008 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 168: /* narth: arth '*' arth  */
#line 809 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                        { CHECK_PTR_VAL(((yyval.a) = gen_arth(cstate, BPF_MUL, (yyvsp[-2].a), (yyvsp[0].a)))); }
#line 3014 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 169: /* narth: arth '/' arth  */
#line 810 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                        { CHECK_PTR_VAL(((yyval.a) = gen_arth(cstate, BPF_DIV, (yyvsp[-2].a), (yyvsp[0].a)))); }
#line 3020 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 170: /* narth: arth '%' arth  */
#line 811 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                        { CHECK_PTR_VAL(((yyval.a) = gen_arth(cstate, BPF_MOD, (yyvsp[-2].a), (yyvsp[0].a)))); }
#line 3026 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 171: /* narth: arth '&' arth  */
#line 812 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                        { CHECK_PTR_VAL(((yyval.a) = gen_arth(cstate, BPF_AND, (yyvsp[-2].a), (yyvsp[0].a)))); }
#line 3032 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 172: /* narth: arth '|' arth  */
#line 813 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                        { CHECK_PTR_VAL(((yyval.a) = gen_arth(cstate, BPF_OR, (yyvsp[-2].a), (yyvsp[0].a)))); }
#line 3038 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 173: /* narth: arth '^' arth  */
#line 814 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                        { CHECK_PTR_VAL(((yyval.a) = gen_arth(cstate, BPF_XOR, (yyvsp[-2].a), (yyvsp[0].a)))); }
#line 3044 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 174: /* narth: arth LSH arth  */
#line 815 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                        { CHECK_PTR_VAL(((yyval.a) = gen_arth(cstate, BPF_LSH, (yyvsp[-2].a), (yyvsp[0].a)))); }
#line 3050 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 175: /* narth: arth RSH arth  */
#line 816 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                        { CHECK_PTR_VAL(((yyval.a) = gen_arth(cstate, BPF_RSH, (yyvsp[-2].a), (yyvsp[0].a)))); }
#line 3056 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 176: /* narth: '-' arth  */
#line 817 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                        { CHECK_PTR_VAL(((yyval.a) = gen_neg(cstate, (yyvsp[0].a)))); }
#line 3062 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 177: /* narth: paren narth ')'  */
#line 818 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                        { (yyval.a) = (yyvsp[-1].a); }
#line 3068 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 178: /* narth: LEN  */
#line 819 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                        { CHECK_PTR_VAL(((yyval.a) = gen_loadlen(cstate))); }
#line 3074 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 179: /* byteop: '&'  */
#line 821 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = '&'; }
#line 3080 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 180: /* byteop: '|'  */
#line 822 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = '|'; }
#line 3086 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 181: /* byteop: '<'  */
#line 823 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = '<'; }
#line 3092 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 182: /* byteop: '>'  */
#line 824 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = '>'; }
#line 3098 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 183: /* byteop: '='  */
#line 825 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = '='; }
#line 3104 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 185: /* pnum: paren pnum ')'  */
#line 828 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.h) = (yyvsp[-1].h); }
#line 3110 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 186: /* atmtype: LANE  */
#line 830 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = A_LANE; }
#line 3116 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 187: /* atmtype: METAC  */
#line 831 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = A_METAC;	}
#line 3122 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 188: /* atmtype: BCC  */
#line 832 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = A_BCC; }
#line 3128 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 189: /* atmtype: OAMF4EC  */
#line 833 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = A_OAMF4EC; }
#line 3134 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 190: /* atmtype: OAMF4SC  */
#line 834 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = A_OAMF4SC; }
#line 3140 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 191: /* atmtype: SC  */
#line 835 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = A_SC; }
#line 3146 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 192: /* atmtype: ILMIC  */
#line 836 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = A_ILMIC; }
#line 3152 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 193: /* atmmultitype: OAM  */
#line 838 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = A_OAM; }
#line 3158 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 194: /* atmmultitype: OAMF4  */
#line 839 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = A_OAMF4; }
#line 3164 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 195: /* atmmultitype: CONNECTMSG  */
#line 840 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = A_CONNECTMSG; }
#line 3170 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 196: /* atmmultitype: METACONNECT  */
#line 841 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = A_METACONNECT; }
#line 3176 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 197: /* atmfield: VPI  */
#line 844 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.blk).atmfieldtype = A_VPI; }
#line 3182 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 198: /* atmfield: VCI  */
#line 845 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.blk).atmfieldtype = A_VCI; }
#line 3188 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 200: /* atmvalue: relop NUM  */
#line 848 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.blk).b = gen_atmfield_code(cstate, (yyvsp[-2].blk).atmfieldtype, (yyvsp[0].h), (yyvsp[-1].i), 0))); }
#line 3194 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 201: /* atmvalue: irelop NUM  */
#line 849 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.blk).b = gen_atmfield_code(cstate, (yyvsp[-2].blk).atmfieldtype, (yyvsp[0].h), (yyvsp[-1].i), 1))); }
#line 3200 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 202: /* atmvalue: paren atmlistvalue ')'  */
#line 850 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                 { (yyval.blk).b = (yyvsp[-1].blk).b; (yyval.blk).q = qerr; }
#line 3206 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 203: /* atmfieldvalue: NUM  */
#line 852 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                   {
	(yyval.blk).atmfieldtype = (yyvsp[-1].blk).atmfieldtype;
	if ((yyval.blk).atmfieldtype == A_VPI ||
	    (yyval.blk).atmfieldtype == A_VCI)
		CHECK_PTR_VAL(((yyval.blk).b = gen_atmfield_code(cstate, (yyval.blk).atmfieldtype, (yyvsp[0].h), BPF_JEQ, 0)));
	}
#line 3217 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 205: /* atmlistvalue: atmlistvalue or atmfieldvalue  */
#line 860 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                        { gen_or((yyvsp[-2].blk).b, (yyvsp[0].blk).b); (yyval.blk) = (yyvsp[0].blk); }
#line 3223 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 206: /* mtp2type: FISU  */
#line 863 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = M_FISU; }
#line 3229 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 207: /* mtp2type: LSSU  */
#line 864 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = M_LSSU; }
#line 3235 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 208: /* mtp2type: MSU  */
#line 865 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = M_MSU; }
#line 3241 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 209: /* mtp2type: HFISU  */
#line 866 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = MH_FISU; }
#line 3247 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 210: /* mtp2type: HLSSU  */
#line 867 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = MH_LSSU; }
#line 3253 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 211: /* mtp2type: HMSU  */
#line 868 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.i) = MH_MSU; }
#line 3259 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 212: /* mtp3field: SIO  */
#line 871 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.blk).mtp3fieldtype = M_SIO; }
#line 3265 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 213: /* mtp3field: OPC  */
#line 872 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.blk).mtp3fieldtype = M_OPC; }
#line 3271 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 214: /* mtp3field: DPC  */
#line 873 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.blk).mtp3fieldtype = M_DPC; }
#line 3277 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 215: /* mtp3field: SLS  */
#line 874 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.blk).mtp3fieldtype = M_SLS; }
#line 3283 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 216: /* mtp3field: HSIO  */
#line 875 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.blk).mtp3fieldtype = MH_SIO; }
#line 3289 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 217: /* mtp3field: HOPC  */
#line 876 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.blk).mtp3fieldtype = MH_OPC; }
#line 3295 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 218: /* mtp3field: HDPC  */
#line 877 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.blk).mtp3fieldtype = MH_DPC; }
#line 3301 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 219: /* mtp3field: HSLS  */
#line 878 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { (yyval.blk).mtp3fieldtype = MH_SLS; }
#line 3307 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 221: /* mtp3value: relop NUM  */
#line 881 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.blk).b = gen_mtp3field_code(cstate, (yyvsp[-2].blk).mtp3fieldtype, (yyvsp[0].h), (yyvsp[-1].i), 0))); }
#line 3313 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 222: /* mtp3value: irelop NUM  */
#line 882 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                { CHECK_PTR_VAL(((yyval.blk).b = gen_mtp3field_code(cstate, (yyvsp[-2].blk).mtp3fieldtype, (yyvsp[0].h), (yyvsp[-1].i), 1))); }
#line 3319 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 223: /* mtp3value: paren mtp3listvalue ')'  */
#line 883 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                  { (yyval.blk).b = (yyvsp[-1].blk).b; (yyval.blk).q = qerr; }
#line 3325 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 224: /* mtp3fieldvalue: NUM  */
#line 885 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                    {
	(yyval.blk).mtp3fieldtype = (yyvsp[-1].blk).mtp3fieldtype;
	if ((yyval.blk).mtp3fieldtype == M_SIO ||
	    (yyval.blk).mtp3fieldtype == M_OPC ||
	    (yyval.blk).mtp3fieldtype == M_DPC ||
	    (yyval.blk).mtp3fieldtype == M_SLS ||
	    (yyval.blk).mtp3fieldtype == MH_SIO ||
	    (yyval.blk).mtp3fieldtype == MH_OPC ||
	    (yyval.blk).mtp3fieldtype == MH_DPC ||
	    (yyval.blk).mtp3fieldtype == MH_SLS)
		CHECK_PTR_VAL(((yyval.blk).b = gen_mtp3field_code(cstate, (yyval.blk).mtp3fieldtype, (yyvsp[0].h), BPF_JEQ, 0)));
	}
#line 3342 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;

  case 226: /* mtp3listvalue: mtp3listvalue or mtp3fieldvalue  */
#line 899 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"
                                          { gen_or((yyvsp[-2].blk).b, (yyvsp[0].blk).b); (yyval.blk) = (yyvsp[0].blk); }
#line 3348 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"
    break;


#line 3352 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (yyscanner, cstate, YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, yyscanner, cstate);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yyscanner, cstate);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (yyscanner, cstate, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, yyscanner, cstate);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yyscanner, cstate);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 901 "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/grammar.y"

