#line 1 "csvscan.rl"
#include <ruby.h>

static VALUE rb_eCSVParseError;
static ID s_read, s_to_str;

#line 70 "csvscan.rl"



#line 12 "csvscan.c"
static const char _csv_scan_actions[] = {
	0, 1, 0, 1, 4, 1, 9, 1, 
	11, 1, 12, 1, 13, 1, 14, 2, 
	2, 3, 2, 5, 6, 2, 5, 7, 
	2, 5, 8, 3, 0, 1, 10, 3, 
	9, 0, 1
};

static const char _csv_scan_key_offsets[] = {
	0, 0, 2, 10, 14, 15
};

static const unsigned char _csv_scan_trans_keys[] = {
	10u, 34u, 9u, 10u, 13u, 32u, 34u, 124u, 
	11u, 12u, 10u, 13u, 34u, 124u, 10u, 34u, 
	0
};

static const char _csv_scan_single_lengths[] = {
	0, 2, 6, 4, 1, 1
};

static const char _csv_scan_range_lengths[] = {
	0, 0, 1, 0, 0, 0
};

static const char _csv_scan_index_offsets[] = {
	0, 0, 3, 11, 16, 18
};

static const char _csv_scan_trans_targs_wi[] = {
	1, 5, 1, 2, 2, 4, 2, 1, 
	2, 3, 3, 2, 2, 2, 2, 3, 
	2, 2, 1, 2, 0
};

static const char _csv_scan_trans_actions_wi[] = {
	1, 24, 0, 5, 31, 0, 5, 0, 
	7, 18, 21, 13, 13, 13, 13, 21, 
	27, 9, 0, 11, 0
};

static const char _csv_scan_to_state_actions[] = {
	0, 0, 15, 0, 0, 0
};

static const char _csv_scan_from_state_actions[] = {
	0, 0, 3, 0, 0, 0
};

static const int csv_scan_start = 2;
static const int csv_scan_error = 0;

static const int csv_scan_en_main = 2;

#line 73 "csvscan.rl"

#define BUFSIZE 131072

VALUE csv_scan(VALUE self, VALUE port) {
    int cs, act, have = 0, nread = 0, curline = 1;
    unsigned char *tokstart = NULL, *tokend = NULL, *buf;
    VALUE row, coldata;
    VALUE bufsize = Qnil;
    int done=0, buffer_size;

    if ( !rb_respond_to( port, s_read ) ) {
        if ( rb_respond_to( port, s_to_str ) ) {
            port = rb_funcall( port, s_to_str, 0 );
            StringValue(port);
        } else {
            rb_raise( rb_eArgError, "bad argument, String or IO only please." );
        }
    }

    buffer_size = BUFSIZE;
    if (rb_ivar_defined(self, rb_intern("@buffer_size")) == Qtrue) {
        bufsize = rb_ivar_get(self, rb_intern("@buffer_size"));
        if (!NIL_P(bufsize)) {
            buffer_size = NUM2INT(bufsize);
        }
    }
    buf = ALLOC_N(unsigned char, buffer_size);

    
#line 98 "csvscan.c"
	{
	cs = csv_scan_start;
	tokstart = 0;
	tokend = 0;
	act = 0;
	}
#line 102 "csvscan.rl"

    row = rb_ary_new();
    coldata = Qnil;

    while( !done ) {
        VALUE str;
        unsigned char *p = buf + have, *pe;
        int len, space = buffer_size - have;

        if ( space == 0 ) {
            rb_raise(rb_eCSVParseError, "ran out of buffer on line %d.", curline);
        }

        if ( rb_respond_to( port, s_read ) ) {
            str = rb_funcall( port, s_read, 1, INT2FIX(space) );
        } else {
            str = rb_str_substr( port, nread, space );
        }

        StringValue(str);
        memcpy( p, RSTRING(str)->ptr, RSTRING(str)->len );
        len = RSTRING(str)->len;
        nread += len;

        /* If this is the last buffer, tack on an EOF. */
        if ( len < space ) {
            p[len++] = 0;
            done = 1;
        }

        pe = p + len;
        
#line 138 "csvscan.c"
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const unsigned char *_keys;

	if ( p == pe )
		goto _out;
	if ( cs == 0 )
		goto _out;
_resume:
	_acts = _csv_scan_actions + _csv_scan_from_state_actions[cs];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 ) {
		switch ( *_acts++ ) {
	case 4:
#line 1 "csvscan.rl"
	{tokstart = p;}
	break;
#line 159 "csvscan.c"
		}
	}

	_keys = _csv_scan_trans_keys + _csv_scan_key_offsets[cs];
	_trans = _csv_scan_index_offsets[cs];

	_klen = _csv_scan_single_lengths[cs];
	if ( _klen > 0 ) {
		const unsigned char *_lower = _keys;
		const unsigned char *_mid;
		const unsigned char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _csv_scan_range_lengths[cs];
	if ( _klen > 0 ) {
		const unsigned char *_lower = _keys;
		const unsigned char *_mid;
		const unsigned char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += ((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	cs = _csv_scan_trans_targs_wi[_trans];

	if ( _csv_scan_trans_actions_wi[_trans] == 0 )
		goto _again;

	_acts = _csv_scan_actions + _csv_scan_trans_actions_wi[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 10 "csvscan.rl"
	{
        curline += 1;
    }
	break;
	case 1:
#line 20 "csvscan.rl"
	{
          rb_ary_push(row, coldata);
          rb_yield(row);
          coldata = Qnil;
          row = rb_ary_new();
      }
	break;
	case 5:
#line 1 "csvscan.rl"
	{tokend = p+1;}
	break;
	case 6:
#line 19 "csvscan.rl"
	{act = 1;}
	break;
	case 7:
#line 30 "csvscan.rl"
	{act = 4;}
	break;
	case 8:
#line 49 "csvscan.rl"
	{act = 5;}
	break;
	case 9:
#line 19 "csvscan.rl"
	{tokend = p+1;}
	break;
	case 10:
#line 25 "csvscan.rl"
	{tokend = p+1;}
	break;
	case 11:
#line 26 "csvscan.rl"
	{tokend = p+1;{
          rb_ary_push(row, coldata);
          coldata = Qnil;
      }}
	break;
	case 12:
#line 19 "csvscan.rl"
	{tokend = p;p--;}
	break;
	case 13:
#line 49 "csvscan.rl"
	{tokend = p;p--;{
          unsigned char ch, *start_p, *wptr, *rptr;
          int rest, datalen;
          start_p = wptr = tokstart;
          rptr = tokstart + 1;
          rest = tokend - tokstart - 2;
          datalen = 0;
          while(rest>0) {
              ch = *rptr++;
              if (ch=='"') {
                rptr++;
                rest--;
              }
              *wptr++ = ch;
              datalen++;
              rest--;
          }
          coldata = rb_str_new( start_p, datalen );
      }}
	break;
	case 14:
#line 1 "csvscan.rl"
	{	switch( act ) {
	case 0:
	{{cs = 0; goto _again;}}
	break;
	case 4:
	{{p = ((tokend))-1;}
          unsigned char ch, *endp;
          int datalen;
          datalen = tokend - tokstart;
          endp = tokend - 1;
          while(datalen>0) {
              ch = *endp--;
              if (ch==' ' || ch=='\t') {
                  datalen--;
              } else {
                  break;
              }
          }
          if (datalen==0) {
              coldata = Qnil;
          } else {
              coldata = rb_str_new(tokstart, datalen);
          }
      }
	break;
	case 5:
	{{p = ((tokend))-1;}
          unsigned char ch, *start_p, *wptr, *rptr;
          int rest, datalen;
          start_p = wptr = tokstart;
          rptr = tokstart + 1;
          rest = tokend - tokstart - 2;
          datalen = 0;
          while(rest>0) {
              ch = *rptr++;
              if (ch=='"') {
                rptr++;
                rest--;
              }
              *wptr++ = ch;
              datalen++;
              rest--;
          }
          coldata = rb_str_new( start_p, datalen );
      }
	break;
	default: break;
	}
	}
	break;
#line 347 "csvscan.c"
		}
	}

_again:
	_acts = _csv_scan_actions + _csv_scan_to_state_actions[cs];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 ) {
		switch ( *_acts++ ) {
	case 2:
#line 1 "csvscan.rl"
	{tokstart = 0;}
	break;
	case 3:
#line 1 "csvscan.rl"
	{act = 0;}
	break;
#line 364 "csvscan.c"
		}
	}

	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_out: {}
	}
#line 134 "csvscan.rl"

        if ( cs == csv_scan_error ) {
            free(buf);
            rb_raise(rb_eCSVParseError, "parse error on line %d.", curline);
        }

        if ( tokstart == 0 ) {
            have = 0;
        } else {
            have = pe - tokstart;
            memmove( buf, tokstart, have );
            tokend = buf + (tokend - tokstart);
            tokstart = buf;
        }
    }
    free(buf);
    return Qnil;
}

void Init_csvscan() {
  VALUE mCSVScan = rb_define_module("CSVScan");
  rb_define_attr(rb_singleton_class(mCSVScan), "buffer_size", 1, 1);
  rb_define_singleton_method(mCSVScan, "scan", csv_scan, 1);
  rb_eCSVParseError = rb_define_class_under(mCSVScan, "ParseError", rb_eException);

  s_read = rb_intern("read");
  s_to_str = rb_intern("to_str");
}
