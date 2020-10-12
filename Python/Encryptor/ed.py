from tqdm import trange
from time import sleep

def encrypt(key, msg):
    encryped = []
    for i, c in enumerate(msg):
        key_c = ord(key[i % len(key)])
        msg_c = ord(c)
        encryped.append(chr((msg_c + key_c) % 64))
    return ''.join(encryped)

def decrypt(key, encryped):
    msg = []

    for i, c in enumerate(encryped):
        key_c = ord(key[i % len(key)])
        enc_c = ord(c)
        msg.append(chr((enc_c - key_c) % 64))
    return ''.join(msg)

if __name__ == '__main__':
    print("   Hi, I'm Mithil's Cryption   ".center(100, '+'))
    print("\n\tKindly, choose \n\t\t1.For Encryption \n\t\t2.For Decrpytion")
    x = input("\n\tEnter your choice in Numeric Format: ")
    if int(x) == 1:
        msg = input('\n\tEnter the text to be encrypted:\t')
        key = input('\n\tEnter the Key(no spaces):\t')
        encrypted = encrypt(key, msg)
        for i in trange(15, desc="Encrypting", unit="data", unit_scale=1000, ascii=False):
            sleep(0.1)
        print('\n\tThe Encrypted Key:\t'+repr(encrypted))
        print('\n\tNote: Remember both your password and Encrypted key.')
    elif int(x) == 2:
        encrypted = input('\n\tEnter the text to be decrypted:\t')
        key = input('\n\tEnter the Key(or the Password for the Text):\t')
        decrypted = decrypt(key, encrypted)
        for i in trange(15, desc="Decrypting", unit="data", unit_scale=1000, ascii=False):
            sleep(0.1)
        print('\n\tThe Original value:\t'+repr(decrypted))
    else:
        print("I can't get you, try again!")
