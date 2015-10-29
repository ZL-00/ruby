/**********************************************************************

  encindex.h -

  $Author$
  created at: Tue Sep 15 13:21:14 JST 2015

  Copyright (C) 2015 Yukihiro Matsumoto

**********************************************************************/

#ifndef RUBY_ENCINDEX_H
#define RUBY_ENCINDEX_H 1
#if defined(__cplusplus)
extern "C" {
#if 0
} /* satisfy cc-mode */
#endif
#endif

enum ruby_preserved_encindex {
    RUBY_ENCINDEX_ASCII,
    RUBY_ENCINDEX_UTF_8,
    RUBY_ENCINDEX_US_ASCII,

    /* preserved indexes */
    RUBY_ENCINDEX_UTF_16BE,
    RUBY_ENCINDEX_UTF_16LE,
    RUBY_ENCINDEX_UTF_32BE,
    RUBY_ENCINDEX_UTF_32LE,
    RUBY_ENCINDEX_UTF_16,
    RUBY_ENCINDEX_UTF_32,
    RUBY_ENCINDEX_UTF8_MAC,

    /* for old options of regexp */
    RUBY_ENCINDEX_EUC_JP,
    RUBY_ENCINDEX_Windows_31J,

    RUBY_ENCINDEX_BUILTIN_MAX
};

#define ENCINDEX_ASCII       RUBY_ENCINDEX_ASCII
#define ENCINDEX_UTF_8       RUBY_ENCINDEX_UTF_8
#define ENCINDEX_US_ASCII    RUBY_ENCINDEX_US_ASCII
#define ENCINDEX_UTF_16BE    RUBY_ENCINDEX_UTF_16BE
#define ENCINDEX_UTF_16LE    RUBY_ENCINDEX_UTF_16LE
#define ENCINDEX_UTF_32BE    RUBY_ENCINDEX_UTF_32BE
#define ENCINDEX_UTF_32LE    RUBY_ENCINDEX_UTF_32LE
#define ENCINDEX_UTF_16      RUBY_ENCINDEX_UTF_16
#define ENCINDEX_UTF_32      RUBY_ENCINDEX_UTF_32
#define ENCINDEX_UTF8_MAC    RUBY_ENCINDEX_UTF8_MAC
#define ENCINDEX_EUC_JP      RUBY_ENCINDEX_EUC_JP
#define ENCINDEX_Windows_31J RUBY_ENCINDEX_Windows_31J
#define ENCINDEX_BUILTIN_MAX RUBY_ENCINDEX_BUILTIN_MAX

#define rb_ascii8bit_encindex() RUBY_ENCINDEX_ASCII
#define rb_utf8_encindex()      RUBY_ENCINDEX_UTF_8
#define rb_usascii_encindex()   RUBY_ENCINDEX_US_ASCII

#ifdef RUBY_ENCODING_H
#define ENC_INDEX_MASK (~(~0U<<24))
#define ENC_TO_ENCINDEX(enc) (int)((enc)->ruby_encoding_index & ENC_INDEX_MASK)

static inline int
enc_to_index(rb_encoding *enc)
{
    return enc ? ENC_TO_ENCINDEX(enc) : 0;
}

static inline int
str_enc_get_index(VALUE str)
{
    int i = ENCODING_GET_INLINED(str);
    if (i == ENCODING_INLINE_MAX) {
	VALUE iv = rb_ivar_get(str, rb_id_encoding());
	i = NUM2INT(iv);
    }
    return i;
}
#endif

#if defined(__cplusplus)
#if 0
{ /* satisfy cc-mode */
#endif
}  /* extern "C" { */
#endif

#endif /* RUBY_ENCINDEX_H */
