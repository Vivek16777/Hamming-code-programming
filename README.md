# Hamming-code-programming
The repository contain hamming code error detection and correction programming in c++ . How the data is collected, how it is encoded, how parity bits are added and how it is decoded and how error being detected
// 1. check the number of bits in data input r.
// 2. find the number of parity bits from formula 2^p <=m+r+1.
// 3. find the parity position with help of 2^0 to 2^p.
// 4. assign the data inputed in the array leaving the box for parity bits.
// 5. find out all the bits which the parity bits check with help of anding parity bit position and position of bit in array.
// 6. find the parity bit value of exoring with the bits that the parity bit check.
// 6. insert the parity value in the parity positiion in array.
// 7. send data to reciever , after reciever recieve the data check the parity bits by exoring with the bits that parity bit check
// 8. if the parity value is 1 then add it and the final value gives the error position
// 9. at the error position change the bit or flip it by exoring with 1
// 10. display the decoded bit
