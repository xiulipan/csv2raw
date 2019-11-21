# csv2raw

A tool to convert SSP signal csv format from Logic Analyzer.
The csv format should be like following.
Example is from Saleae Logic 8 with `Dec` Output dump file.

```
Time [s],Channel,Value
2.012651128000000,2,676608
2.012661544000000,1,668800
2.012671960000000,2,668800
2.012682376000000,1,660992
2.012692792000000,2,660992
2.012703208000000,1,650624
2.012713624000000,2,650624
2.012724040000000,1,637568
2.012734456000000,2,637568
```

## Build:
```
make
```

## Usage:

```
./csv2raw -i INPUT.csv -o OUTPUT.raw
```

### Note:
Only support to convert S24_LE to S32_LE now

## TODO:
Add format convertion between S16_LE, S24_LE and S32_LE
