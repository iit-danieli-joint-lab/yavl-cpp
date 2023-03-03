# yavl-cpp

YAVL-CPP is a C++ library to check if a given YAML file follows an
expected schema. For example, you can use this to check if a
configuration file has the tree structure that your program
expects to have.

This library checks if the input YAML has the tree structure
(i.e., keys, values, types, nesting of keys) that the
specification expects. See example below.

To be clear, this is not a tool to check if the input file is a
valid YAML; any YAML parser will do that.

The tree specification file is also written in YAML.

This library saves you the hassle of writing code to emit error
messages about what is wrong about the input file. Your code
can be written assuming that it only ever works with input
that conforms to an expected schema.

Structures such as lists of lists, maps of lists,
lists etc can be nicely checked.

## Example Tree Specification

```yaml
map:
  HEADER:
    map:
      name: [string: ]
      version: [string: ]
      size: [enum: [big, small]]
      pieces:
        map:
          a:
            list: [string: ]
          b:
            list: [uint64: ]
```

Notice that HEADER.pieces.a is list nested within
the map HEADER.pieces. You can have arbitrary levels
of nesting, and also do things like maps within lists.

### Valid YAML

```yaml
HEADER:
  name: myname
  version: 1.02
  size: big
  pieces:
    a: [hello, world]
    b: [100, 200]
```

### Invalid YAML

```yaml
HEADER:
  name: myname
  version: 1.02
  size: xbig
  pieces:
    a: [hello, world]
    b: [x100, 200]
```

With the invalid YAML, you'll get an errors that 'xbig'
is not allowed and that 'x100' could not be converted to
a 'long long'.

## Mentions

Original code by: https://code.google.com/archive/p/yavl-cpp/

YAML-cpp: https://github.com/jbeder/yaml-cpp
