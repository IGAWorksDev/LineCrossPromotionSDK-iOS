Pod::Spec.new do |s|
s.name         = "LineCrossPromotionSDK"
s.version      = "1.2.3"
s.summary      = "LineCrossPromotionSDK.framework"
s.homepage     = "https://github.com/IGAWorksDev/LineCrossPromotionSDK-iOS"

s.license      = {
:type => 'Commercial',
:text => <<-LICENSE
All text and design is copyright 2006-2016 igaworks, Inc.

All rights reserved.

https://github.com/IGAWorksDev/LineCrossPromotionSDK-iOS
LICENSE
}

s.platform = :ios, '6.0'
s.author       = { "wonje,song" => "ricky@igaworks.com" }
s.source       = { :git => "https://github.com/IGAWorksDev/LineCrossPromotionSDK-iOS.git", :tag => "#{s.version}" }
s.resources = "LineCrossPromotionSDK.bundle"
s.ios.vendored_frameworks = 'LineCrossPromotionSDK.framework'
s.frameworks = 'iAd', 'CoreTelephony', 'SystemConfiguration', 'UIKit', 'Security', 'CoreGraphics', 'CoreText', 'MobileCoreServices', 'Foundation', 'ImageIO', 'MessageUI', 'MediaPlayer', 'AdSupport', 'AVKit', 'AVFoundation', 'CoreMedia'
s.libraries = 'xml2'
s.xcconfig     = { 'HEADER_SEARCH_PATHS' => '"$(SDKROOT)/usr/include/libxml2"' }
end
