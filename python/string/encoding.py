
# encode() converts a string to bytes, decode() simply does the reverse.
#
# UTF-8 is a compromise character encoding that can be as compact as ASCII but
# can also contain any unicode characters.
#
# The '8' means it uses 8-bit blocks to represent a character. The number of
# blocks needed to represent a character varies from 1 to 4.
#
# Encoding:
#   https://www.askpython.com/python/string/python-encode-and-decode-functions
#
# UTF-8: https://www.fileformat.info/info/unicode/utf8.htm

if __name__ == '__main__':
    # 1-block character
    a = "Ab"
    
    # utf-8 used by default
    a_enc = a.encode()
    a_dec = a_enc.decode()

    print("original:", a)
    print("encoded:", a_enc, type(a_enc))
    print("binary form:", bin(int.from_bytes(a_enc, 'big')))
    print("decoded:", a_dec)

    # 2-blocks character
    a = "\xcb"
    a_enc = a.encode()
    a_dec = a_enc.decode()

    print('')
    print("original:", a)
    print("encoded:", a_enc, type(a_enc))
    print("binary form:", bin(int.from_bytes(a_enc, 'big')))
    print("decoded:", a_dec)

    
    # Handling errors
    a = 'A cömplex sentence.'

    print('')
    print('original:', a)
    print('errors=ignore:', a.encode('ascii', 'ignore'))
    print('errors=replace:', a.encode('ascii', 'replace'))

