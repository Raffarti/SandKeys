themes = ClassicBlack LightWeight



for(theme, themes){
    include($$theme/$$theme".pri")
}

TEMPLATE = subdirs
