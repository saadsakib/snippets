import base64

# Base64 encoding is a type of conversion of bytes into ASCII characters.
#
# Standard Base64 alphabet contains:
#
# 26 uppercase letters
# 26 lowercase letters
# 10 numbers
# + and /
# 
# URL- and filesystem-safe alphabet substitutes - and _ instead of + and /
# 
# Groups of 6 bits are converted into characters from left to right. Sometimes
# we have to pad the sequence. 
# 
# Base64 encoding:
#   https://docs.python.org/3/library/base64.html
#   https://stackabuse.com/encoding-and-decoding-base64-strings-in-python/

def encode_txt(msg):
    return base64.b64encode(msg.encode()).decode()

def decode_txt(b64_msg):
    return base64.b64decode(b64_msg.encode()).decode()

def urlsafe_encode_txt(msg):
    return base64.urlsafe_b64encode(msg.encode()).decode()

def urlsafe_decode_txt(b64_msg):
    return base64.urlsafe_b64decode(b64_msg.encode()).decode()

def encode_bin(a_file):
    with open(a_file, 'rb') as f:
        return base64.b64encode(f.read()).decode('utf-8')

def decode_bin(b64_msg, file_dec):
    with open(file_dec, 'wb') as f:
        f.write(base64.b64decode(b64_msg.encode('utf-8')))

if __name__ == '__main__':
    # Encoding text
    msg = "It~s not\x7F URL-safe"
    b64_msg = encode_txt(msg)
    msg_dec = decode_txt(b64_msg)
    
    print("original:", msg)
    print("encoded:", b64_msg)
    print("decoded:", msg_dec)

    # URL-safe encoding
    b64_msg = urlsafe_encode_txt(msg)
    msg_dec = urlsafe_decode_txt(b64_msg)
    
    print('')
    print("urlsafe encoded:", b64_msg)
    print("urlsafe decoded:", msg_dec)

    # Encoding binary
    a_file = 'image.png'
    b64_msg = encode_bin(a_file)
    decode_bin(b64_msg, 'decoded_image.png')

    # print("encoded binary:", b64_msg) 
    