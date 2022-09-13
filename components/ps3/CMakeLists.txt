idf_component_register(SRCS "src/ps3.c"
                            "src/ps3_spp.c"
                            "src/ps3_parser.c"
                            "src/ps3_l2cap.c"
                        REQUIRES nvs_flash bt
                        PRIV_REQUIRES bt
                        INCLUDE_DIRS src/include
                        PRIV_INCLUDE_DIRS   ${IDF_PATH}/components/bt/common/include/
                                            ${IDF_PATH}/components/bt/host/bluedroid/common/include/
                                            ${IDF_PATH}/components/bt/host/bluedroid/stack/include)