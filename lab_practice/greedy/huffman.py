# huffman encoding and then decoding
def hufmann_encode(data):
    joined_chars = []
    freq = {} 
    for d in data:
        if d not in freq:
            freq[d] = 1
        else:
            freq[d] += 1

    freq = {k: v for k, v in sorted(freq.items(), key=lambda item: item[1])}
    keys = list(freq.keys())

    n_key= ""
    n_value= 0
    t = 0
    print(keys)
    # while joined_chars != keys:
    #     for key,value in freq.items():
    #        if key not in joined_chars:
    #            t+=1
    #            n_key += key 
    #            n_value += value
    #            joined_chars.append(n_value)
    #        if(t==2):
    #            break
    #
    #     freq[n_key] = n_value
    #     freq = {k: v for k, v in sorted(freq.items(), key=lambda item: item[1])}

    return freq

print(hufmann_encode("datastructures"))


